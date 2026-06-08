# AWS for Production / Microservices

notes on how real apps actually get deployed on aws and how the pieces fit together

## what "microservices" even means

- instead of one giant app (monolith), you split into small services that each
  do ONE job and talk to each other over the network (HTTP, gRPC, or queues)
- e.g. auth-service, payment-service, notification-service, upload-service
- each can be deployed, scaled, and owned independently
- tradeoff: more flexibility + independent scaling, but way more operational
  complexity (networking, monitoring, "which service is down?")

start with a monolith. split into services only when you actually feel the pain.

## the core building blocks

### compute - where your code runs

- EC2 - raw virtual machines. you manage the OS, patches, everything. most control
- ECS / Fargate - run containers (docker). Fargate = serverless, no servers to manage
- EKS - managed kubernetes. powerful but heavy, only if you need k8s
- Lambda - serverless functions. runs on an event, scales to zero, pay per request
  - great for: image processing, webhooks, cron jobs, glue code
  - bad for: long-running tasks, anything needing >15 min

rule of thumb: Lambda for events/spiky load, Fargate for always-on services,
EC2 only when you need special hardware or full control.

### networking / routing

- VPC - your private network. subnets (public vs private), security groups (firewalls)
- API Gateway - front door for APIs. routing, auth, rate limiting, throttling
- ALB (Application Load Balancer) - spreads traffic across container/EC2 instances
- Route 53 - DNS (domain names -> your load balancer)
- CloudFront - CDN, caches static content at edge locations near users

### data

- RDS - managed SQL (postgres, mysql). aws handles backups/patching/failover
- DynamoDB - managed NoSQL key-value. serverless, scales massively, single-digit ms
- ElastiCache - managed Redis/Memcached for caching + sessions
- S3 - object storage for files/assets (see s3.txt)

### async / glue between services

this is the heart of microservices - services shouldn't call each other directly
all the time. use queues/events so they're decoupled.

- SQS - message queue. service A drops a message, service B processes it later.
  if B is down, messages wait. smooths out spikes.
- SNS - pub/sub. one event -> fan out to many subscribers
- EventBridge - event bus, route events by rules (more powerful SNS)
- Kinesis - streaming data (logs, clickstreams, real-time analytics)

example flow:
user uploads video -> S3 -> S3 event -> SQS -> transcoder service picks it up
                                                -> writes result back to S3 + DB

### observability (you NEED this in prod)

- CloudWatch - logs, metrics, alarms, dashboards
- X-Ray - distributed tracing (follow one request across multiple services)
- without this you're flying blind when something breaks at 3am

## a typical production setup

```
        Route 53 (DNS)
            |
        CloudFront (CDN, static assets from S3)
            |
        API Gateway / ALB
            |
    +--------+--------+
   |        |         |
 auth    orders    uploads     <- containers on ECS/Fargate (or Lambdas)
   |        |         |
  RDS   DynamoDB     S3
   |        |
   +---> SQS / SNS / EventBridge  (async between services)
            |
        CloudWatch + X-Ray (watching everything)
```

## things that matter in production

- IAM - least privilege. give each service ONLY the permissions it needs
- Secrets - never hardcode keys. use Secrets Manager or SSM Parameter Store
- Infrastructure as Code - don't click around the console. use Terraform or CDK
  so your infra is version controlled + reproducible
- CI/CD - auto deploy on git push (CodePipeline, or GitHub Actions -> aws)
- auto scaling - scale containers up/down based on CPU/traffic
- health checks - load balancer pings each instance, kills unhealthy ones
- multi-AZ - run across availability zones so one datacenter dying != outage
- cost - tag everything, set billing alarms. easy to get a surprise bill

## mental model

aws is basically lego blocks. you're not learning "aws", you're learning
which block does what and how to snap them together:

- need to run code? -> Lambda / Fargate / EC2
- need to store files? -> S3
- need a database? -> RDS / DynamoDB
- need services to talk without blocking? -> SQS / SNS / EventBridge
- need to expose an API? -> API Gateway / ALB
- need to know what's happening? -> CloudWatch

## what to actually learn first (order)

1. IAM (permissions) - everything depends on it
2. S3 - easiest, most used
3. EC2 + VPC basics - understand the network
4. RDS or DynamoDB - pick one
5. Lambda - serverless mindset
6. ECS/Fargate - running containers
7. SQS/SNS - async communication
8. CloudWatch - monitoring
