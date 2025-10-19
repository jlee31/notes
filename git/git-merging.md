# Git Merghing Notes

### if you have a conflict and you want to overwrite a conflicted file with the remote version during a merge

```
git checkout --theirs path\to\conflicted_file
```

then stage, add and commit

if you want to keep the local version, use --ours


### fast forward merge 

when you want to merge a branch that is directly ahead of the current branch with no diverging changes

```
git checkout main
git merge feature branch
```

### merge conflicts
if theres a merge conflict, there will be markers with <<<<< or ===== or >>>>>

- open the conflicted file
- manually edit to resolve

```
git add <files>
git commit
```

### merge fails due to uncommited changes

looks like this:  error: Your local changes to the following files would be overwritten by merge

```  
git stash
git merge <branch>
git stash pop
```

