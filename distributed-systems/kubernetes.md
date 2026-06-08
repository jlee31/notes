# Kubernetes (k8s)

a system for running and managing containers across a bunch of machines.
you describe the state you want ("run 3 copies of my app"), k8s makes it true
and KEEPS it true (a container dies -> it restarts one).

docker = run one container. kubernetes = run thousands of containers across
many servers, with healing, scaling, networking, and rollouts handled for you.

the "k8s" thing = k + 8 letters + s. people are lazy.

## why it exists / what problem it solves

once you have more than a couple containers you hit questions like:
- one server isn't enough, how do I spread containers across many?
- a container crashed at 3am, who restarts it?
- traffic spiked, how do I add more copies automatically?
- I pushed a bad version, how do I roll back without downtime?
- how do containers find + talk to each other?

k8s answers all of these. that's it. it's a container babysitter at scale.

## core concepts (the vocabulary)

- cluster - the whole thing. a set of machines k8s runs on
- node - one machine (VM or physical) in the cluster
  - control plane / master - the brain. decides what runs where (the API server lives here)
  - worker node - where your actual containers run
- pod - smallest unit. wraps 1 (usually) container. k8s schedules PODS, not containers
- deployment - "I want N copies of this pod, this version". handles scaling + rollouts
- replicaset - keeps N pods alive (deployments manage these for you)
- service - stable network address + load balancing for a set of pods
  (pods die and get new IPs constantly; a service gives them one fixed front door)
- ingress - routes outside HTTP traffic to services (the front door from the internet)
- configmap - non-secret config (env vars, settings)
- secret - sensitive config (passwords, tokens) - base64, not truly encrypted by default
- namespace - logical partition of the cluster (e.g. dev vs prod vs team-a)
- volume / PersistentVolume - storage that survives pod restarts (pods are ephemeral)

## the mental model

you write YAML files that DECLARE the desired state.
k8s constantly compares "what's running" vs "what you asked for" and fixes the gap.
this is the whole idea: declarative + self-healing. you don't run commands to
fix things, you change the desired state and k8s reconciles.

```
you: "I want 3 replicas of app v2"
k8s: *makes it so, and re-makes it every time reality drifts*
```

## a minimal deployment (YAML)

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: my-app
spec:
  replicas: 3                 # run 3 copies
  selector:
    matchLabels:
      app: my-app
  template:
    metadata:
      labels:
        app: my-app
    spec:
      containers:
        - name: my-app
          image: myrepo/my-app:1.0
          ports:
            - containerPort: 8080
---
apiVersion: v1
kind: Service
metadata:
  name: my-app
spec:
  selector:
    app: my-app              # routes to the pods above
  ports:
    - port: 80
      targetPort: 8080
```

## kubectl - the CLI you live in

```
kubectl apply -f deploy.yaml     # create/update from a yaml file (the main command)
kubectl get pods                 # list pods
kubectl get all                  # everything in the namespace
kubectl describe pod NAME        # detailed info / events (debugging)
kubectl logs NAME                # container logs
kubectl logs -f NAME             # follow logs (live)
kubectl exec -it NAME -- sh      # shell into a running container
kubectl scale deploy my-app --replicas=5
kubectl rollout undo deploy/my-app   # roll back a bad deploy
kubectl delete -f deploy.yaml
```

## how scaling + healing actually works

- liveness probe - "is this container alive?" fails -> k8s restarts it
- readiness probe - "is it ready for traffic?" fails -> k8s stops sending it requests
- HPA (Horizontal Pod Autoscaler) - auto add/remove pods based on CPU/memory/custom metrics
- rolling updates - new version rolls out pod-by-pod, old ones drain, zero downtime
  - if it breaks, `rollout undo` snaps back

## the ecosystem you'll hit

- Helm - package manager for k8s ("apt/npm for clusters"). installs apps as "charts"
- kustomize - template/overlay your YAML per environment (built into kubectl)
- managed k8s - nobody runs the control plane themselves if they can avoid it:
  - EKS (aws), GKE (google), AKS (azure)
- local k8s for learning - minikube, kind, k3s, or Docker Desktop's built-in k8s
- service mesh - Istio / Linkerd (advanced traffic mgmt between services)
- monitoring - Prometheus + Grafana is the standard combo

## honest take / when NOT to use it

- k8s is HEAVY. huge learning curve, lots of moving parts, easy to overcomplicate
- a solo project or simple app does NOT need kubernetes. use:
  - a single docker container on a VM
  - docker compose
  - a PaaS (Railway, Render, Fly.io, ECS Fargate, App Engine)
- reach for k8s when you genuinely have: many services, multiple teams,
  need fine-grained scaling/control, or multi-cloud requirements
- "we used kubernetes for our 3-user startup" is a classic overengineering meme

## mental model recap

- docker builds + runs a container
- kubernetes runs MANY containers, across MANY machines, and keeps them healthy
- you declare desired state in YAML -> k8s reconciles reality to match
- you talk to it through `kubectl apply`
