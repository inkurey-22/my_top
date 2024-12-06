# my_top
`my_top` is an EPITECH project from the Unix Shell Programming unit.
The goal is to reproduce the `top` command that lists processes and informations on your system.

## Objectives
The project is entirely coded in C with the `ncurses` library, so make sure to have it installed.

The whole standard C library was authorized except functions like `system`, `exec`, `execve`..., `getloadavg` or any functions retrieving process or system informations for us.
The main goal was to make our way through the `/proc` filesystem to find, parse and display the right informations.

## Achievements
All "header" lines are complete, except for the `%Cpu(s)` one.
In the process list, I have everythint except `%CPU`, `%MEM` and `TIME+`.
The `VIRT` and `RES` columns are here but aren't converted to GiB when needed.

K(ill) command is enabled, prompting you for a process and a signal to send.
Arrows up and down make you go through the process list.
You can use the `Q` key to quit.

## Usage
This project is to be built by the Makefile at the root of the repo.

```bash
make
./my_top
```
