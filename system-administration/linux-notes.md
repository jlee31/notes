# LINUX

Learn essential commands (ls, cd, cat, grep, ps, top, chmod, chown, find, awk, sed, etc.).
learn the filesystem hierarchy
learn package management
Learn about system processes and services
- Explore systemd commands (systemctl) to manage services.
- Understand how to start, stop, enable, disable services.
- Check system logs (journalctl).

###  text-based user interfaces (TUIs)

1. htop
A colorful, interactive process viewer and system monitor.

You can scroll through processes, kill tasks, see CPU/memory usage live — all inside the terminal.

2. midnight commander (mc)
A text-based file manager with panels, navigation, and file operations.

It looks like a mini file explorer but inside your terminal.

3. nano / vim / emacs
Text editors that run inside the terminal, with various interfaces for editing files.

4. tmux / screen
Terminal multiplexers that let you split your terminal into multiple panes and sessions, kind of like tabs inside the terminal.

5. ncurses-based apps
Many Linux tools use the ncurses library to build TUIs — colorful, keyboard-driven UIs that run inside terminals.

Examples: nmtui (network manager), alsamixer (audio mixer), irssi (IRC client), tig (Git repository browser).

### wsl 
windows subsystem for linux
- allows you to run linux directly inside windows 
- lets you use linux tools with windows programs

WSL 1 vs WSL 2
WSL 1 is a translation layer that runs Linux binaries on Windows.

WSL 2 uses a lightweight virtual machine with a real Linux kernel, giving better performance and full system call compatibility.