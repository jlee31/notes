# Distributed Systems

This folder contains notes about running software across many machines — container orchestration, scaling, and the patterns that make systems reliable at scale.

## Files in this folder:

- **`kubernetes.md`** - Kubernetes (k8s) guide covering core concepts (pods, deployments, services, ingress), the declarative/self-healing mental model, a minimal deployment YAML, kubectl commands, scaling + healing (probes, HPA, rolling updates), the surrounding ecosystem (Helm, managed k8s, monitoring), and an honest take on when NOT to use it

## Topics Covered:

- Container orchestration and why it exists
- Kubernetes core objects (cluster, node, pod, deployment, service, ingress)
- Declarative configuration and self-healing reconciliation
- Scaling (HPA) and zero-downtime rolling updates
- The k8s ecosystem (Helm, kustomize, EKS/GKE/AKS, Prometheus/Grafana)
- When to use k8s vs simpler alternatives (compose, PaaS)
