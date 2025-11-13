# What is the zshrc file on my mac

file is
``` bash
~/zshrc
```

- it is a startup script that runs every time you open a zsh shell

you add

1) environment variables

2) aliases

3) customized prompts/themes

4) plugins (with oh my zsh)

5) for loading up other config files

6) startup commands

- this is a sample one made by gpt

``` zsh

# =============================
#  🌟 BASIC SETTINGS
# =============================

# History settings
HISTFILE=~/.zsh_history
HISTSIZE=10000
SAVEHIST=10000
setopt HIST_IGNORE_ALL_DUPS       # Don’t save duplicate commands
setopt HIST_REDUCE_BLANKS         # Clean up whitespace in history

# Auto-correction and completion
setopt CORRECT                    # Suggest fixes for mistyped commands
autoload -Uz compinit && compinit

# =============================
#  🧩 PATH AND ENV VARIABLES
# =============================

# Custom PATH additions
export PATH="$HOME/bin:/usr/local/bin:/opt/homebrew/bin:$PATH"

# Preferred editor
export EDITOR="code"              # or "nvim", "nano", etc.

# Python virtual environments default directory
export WORKON_HOME=$HOME/.virtualenvs

# Node.js version manager (nvm)
export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"

# =============================
#  🎨 APPEARANCE
# =============================

# If using Oh My Zsh
export ZSH="$HOME/.oh-my-zsh"
ZSH_THEME="agnoster"              # or "powerlevel10k/powerlevel10k"

plugins=(
  git
  zsh-autosuggestions
  zsh-syntax-highlighting
  colored-man-pages
  pip
  node
)

source $ZSH/oh-my-zsh.sh

# Prompt customization (if not using Oh My Zsh)
# PROMPT='%F{cyan}%n%f@%F{green}%m%f %F{yellow}%1~%f %# '

# =============================
#  ⚙️ ALIASES
# =============================

# Navigation
alias ..="cd .."
alias ...="cd ../.."
alias c="clear"

# Git shortcuts
alias gs="git status"
alias ga="git add ."
alias gc="git commit -m"
alias gp="git push"
alias gl="git log --oneline --graph --decorate"

# Python helpers
alias py="python3"
alias venv="python3 -m venv venv && source venv/bin/activate"

# Node helpers
alias npms="npm start"
alias npmi="npm install"

# =============================
#  🧠 QUALITY OF LIFE
# =============================

# Enable syntax highlighting and autosuggestions (if installed manually)
if [ -f /opt/homebrew/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh ]; then
  source /opt/homebrew/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
fi
if [ -f /opt/homebrew/share/zsh-autosuggestions/zsh-autosuggestions.zsh ]; then
  source /opt/homebrew/share/zsh-autosuggestions/zsh-autosuggestions.zsh
fi

# =============================
#  🧑‍💻 STARTUP MESSAGE
# =============================
echo "Welcome back, $USER 👋 — $(date '+%A, %B %d')"
echo "Type 'help' for Zsh docs or 'gs' for Git status."

# =============================
#  END OF FILE
# =============================

```