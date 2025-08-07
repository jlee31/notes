# reference : Git Branch Merging Guide

Merging branches in Git is the process of integrating changes from one branch (like a feature or practice branch) into another branch (usually the main branch). This lets you finalize work done separately and combine it into the main project.

To merge a branch into your main branch, follow these commands:

```bash
# Switch to the main branch (replace 'main' with 'master' if needed)
git checkout main

# Make sure your main branch is up to date
git pull origin main

# Merge your practice branch into main
git merge practice-branch

# Push the updated main branch to GitHub
git push origin main

# (Optional) Delete the practice branch locally
git branch -d practice-branch

# (Optional) Delete the practice branch from the remote repository
git push origin --delete practice-branch
```

what is set upstream? it is the same as -u
sets the default remote branch as the current local branch
so you can do git push without setting the branch name