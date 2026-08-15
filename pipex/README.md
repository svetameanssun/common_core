# pipex

The goal of this project is to recreate the mechanism of UNIX pipelines in C, replicating the shell behavior of `< file1 cmd1 | cmd2 > file2`. It provides a deep understanding of process creation, inter-process communication (IPC) via pipes, file descriptor manipulation, and binary execution using system calls.

---

## 💡 Key Concepts
This project introduces the fundamentals of **system programming** and **inter-process communication (IPC)** in UNIX-like operating systems. It helps refine skills in managing parallel processes, redirecting standard input/output streams, executing system binaries, and parsing environment variables to locate executables.

---

## 🧠 Programming Concepts
* **Process Creation & Management:** Using `fork()` to split process execution into parent and child processes, and `waitpid()` for process synchronization.
* **Inter-Process Communication (IPC):** Creating unidirectional data channels using `pipe()` to pass data seamlessly between commands.
* **File Descriptor Redirection:** Using `dup2()` to overwrite standard input (`STDIN_FILENO`) and standard output (`STDOUT_FILENO`) with file or pipe descriptors.
* **Command Execution & PATH Parsing:** Searching the `PATH` variable from `envp`, checking binary access rights with `access()`, and executing binaries via `execve()`.
* **File Handling & Flags:** Opening input/output files with proper access modes (`O_RDONLY`, `O_WRONLY`, `O_CREAT`, `O_TRUNC`) and managing permissions.

---

## 🛠️ Tech Stack
* **Language:** C (C99 Standard)
* **Build System:** Makefile (`all`, `clean`, `fclean`, `re`)
* **OS Interface:** POSIX / UNIX System Calls
* **Version Control:** Git
* **Libraries:** `libft` (if linked)

---

## 🎯 Hard Skills
* **UNIX System Call Mastery:** Direct usage of core low-level system calls (`fork`, `execve`, `pipe`, `dup2`, `open`, `close`, `unlink`, `waitpid`).
* **PATH Resolution Algorithm:** Extracting and parsing environment variables to dynamically resolve full executable paths for shell commands.
* **Pipeline Data Flow Architecture:** Structuring data flow so the output of one process becomes the direct input of the next without writing to disk.
* **Resource & FD Leak Prevention:** Rigorously closing unneeded file descriptors across parent and child processes to avoid hanging processes or memory leaks.

---

## 🤝 Soft Skills
* **System Error Handling:** Emulating shell-accurate error messaging for missing files, invalid commands, and permission denials (`perror`, `strerror`).
* **Edge Case Management:** Safely managing scenarios such as non-existent input files, command execution failures, and empty environment arrays.
* **Norminette Compliance:** Writing clean, structured C code adhering strictly to 42's coding standard.

---

## 📁 Project Structure

```text
.
├── include
│   └── pipex.h
├── libft
│   ├── libft.a
│   └── libft.h
├── Makefile
└── src
    ├── main.c
    ├── manage_cmd.c
    ├── manage_error.c
    ├── pipex.c
    └── set_path.c
