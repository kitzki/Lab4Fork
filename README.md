# Lab4Fork: Process Creation with fork()

## Overview
This lab explores process creation in C using the `fork()` system call. The goal is to understand how a parent process can create child processes, differentiate execution paths, and handle process termination.

---

## Tools and Concepts Learned
- **fork()**: Creates a new child process. Returns:
  - `0` → In child process
  - `>0` → In parent process (returns child PID)
  - `-1` → Fork failed
- **getpid()**: Retrieves the process ID of the current process.
- **getppid()**: Retrieves the parent process ID.
- **wait() / waitpid()**: Allows parent process to wait for child termination.
- Process hierarchy and independent memory spaces.
