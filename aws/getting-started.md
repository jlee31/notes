# Getting Started with AWS (for when you're ready)

no rush. this is a roadmap, not a checklist to do this week. AWS is big and
overwhelming at first - that's normal. you don't need to learn all of it, ever.
people who've used it for years still only touch ~10 services.

read this top to bottom once now, then come back when you actually have a project
that needs it. learning AWS without a project to apply it to doesn't stick.

## the mindset before you start

- you do NOT need to know "AWS". you need to know which ~5 services solve your problem
- it's lego blocks, not a language. you snap pieces together
- the console (web UI) is fine for learning. don't feel bad clicking around
- everything costs money eventually, but the free tier is generous for learning
- it's ok to be slow. this stuff takes months to feel comfortable, not days

## phase 0 - just get an account safe (1 evening)

the only "urgent" things, do these once:

1. make an AWS account
2. turn on MFA (multi-factor auth) on the root login
3. create a billing alarm (e.g. email me if I spend > $5)
   - this is the #1 thing beginners skip and then get a scary bill
4. stop using the root account. make an IAM user for yourself with admin
   - root is only for billing/account-level stuff

that's it for phase 0. you don't have to build anything yet.

## phase 1 - understand the vocabulary (no building)

just get familiar with what these words mean (your other notes cover most):

- region / availability zone - where your stuff physically lives
- IAM - permissions. who can do what. everything depends on this
- S3 - file storage (you already have notes on this)
- EC2 - a virtual computer in the cloud
- the console - the web dashboard where you see everything

goal here is just to not feel lost when you read a tutorial. no pressure to build.

## phase 2 - your first real thing: S3 (a weekend)

S3 is the gentlest entry point. do this in the console:

1. make a bucket
2. upload a file by dragging it in
3. download it back
4. look at the permissions tab, see "Block Public Access" is on
5. (optional) make a tiny bucket that hosts a static html page

you've now "used AWS". it's less scary than it looked. that's the whole point
of phase 2 - kill the fear.

## phase 3 - connect it to code (when you have a project)

this is where it gets real and useful:

1. install the AWS CLI, run `aws configure`, paste in your keys
2. install the SDK for your language (boto3 for python)
3. upload/download a file from S3 in your actual code
4. learn presigned URLs (see s3.md) - the real upload pattern

now AWS is part of a project instead of an abstract thing.

## phase 4 - the "real app" pieces (later, much later)

only when you actually need them, one at a time:

- a database -> RDS (postgres) or DynamoDB
- run your backend somewhere -> EC2, or Fargate (containers), or Lambda
- a domain name -> Route 53
- put it behind a CDN -> CloudFront

don't learn these until a project forces you to. each one will make sense the
moment you have a real reason for it.

## phase 5 - "doing it properly" (way down the road)

the professional habits. ignore these completely until you're comfortable:

- IAM roles instead of access keys (no keys to leak)
- Secrets Manager for passwords/tokens
- Infrastructure as Code (Terraform / CDK) instead of clicking
- CI/CD auto-deploys

## the honest progression

```
account + billing alarm  ->  poke at S3  ->  S3 from code  ->  add a db + compute  ->  Terraform/CI
     1 evening               a weekend       a small project      a real app           a serious app
   (do this soon-ish)       (no pressure)    (when you build)      (later)            (way later)
```

## what to AVOID as a beginner

- don't start with Kubernetes/EKS, VPCs, or Terraform. way too much too soon
- don't try to learn 20 services. learn S3, then IAM, then one more
- don't leave things running you forgot about (EC2 instances cost money idle)
- don't paste your access keys into code or git. ever
- don't feel behind. literally everyone finds AWS overwhelming at first

## the one-sentence version

make an account + billing alarm now, play with S3 when you're curious, and
only learn each new service the day a real project actually needs it.
