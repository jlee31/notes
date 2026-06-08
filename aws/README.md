# AWS

This folder contains notes about Amazon Web Services — building and deploying production applications, microservices architecture, and core managed services.

## Files in this folder:

- **`getting-started.md`** - Beginner-paced roadmap for picking up AWS: phased plan (account safety + billing alarm, learn the vocabulary, first S3 in the console, connecting S3 to code, then databases/compute later), plus what to avoid as a beginner
- **`s3.md`** - S3 (object storage) guide covering buckets/objects/keys, CLI + boto3 usage, presigned URLs, security, storage classes for cost, versioning, lifecycle rules, and event notifications
- **`microservices.md`** - AWS for production: what microservices are (and when to use them), the core building blocks (compute, networking, data, async messaging, observability), a typical prod setup diagram, production best practices, and a suggested learning order

## Topics Covered:

- Object storage with S3 (presigned URLs, security, cost optimization)
- Compute options (EC2, ECS/Fargate, EKS, Lambda) and when to use each
- Networking (VPC, API Gateway, ALB, Route 53, CloudFront)
- Data stores (RDS, DynamoDB, ElastiCache)
- Async communication between services (SQS, SNS, EventBridge, Kinesis)
- Observability (CloudWatch, X-Ray)
- Production practices (IAM least privilege, secrets, IaC, CI/CD, auto-scaling, multi-AZ)
- Microservices mental model and learning roadmap
