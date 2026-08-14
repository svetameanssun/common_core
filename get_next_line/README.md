# get_next_line

The goal of this project is to create a C function, `get_next_line`, that reads and returns a single line from a file descriptor (`fd`) every time it is called. Repeated calls allow reading an entire text file line-by-line until reaching the End Of File (EOF).

---

## 💡 Key Concepts

This project introduces **static variables** in C, which preserve their state across function calls—a necessity for remembering leftover characters read from a file descriptor between consecutive invocations. 

In the **Bonus Part**, the challenge escalates to handling **multiple file descriptors simultaneously** using **only one static variable** (such as an array indexed by `fd`). This allows interleaving calls to `get_next_line` across different open files without losing read positions or mixing up buffers.

---

## 🧠 Programming Concepts
* **Static Variables:** Retaining leftover read buffers across function calls without global state.
**File Descriptors & Low-Level I/O:** Reading data streams sequentially using the `read()` system call and `fcntl.h` / `unistd.h`.
* **Dynamic Memory & Buffer Management:** Dynamically allocating memory (`malloc`/`free`) to stitch together string chunks and prevent memory leaks.
* **String Parsing & Extraction:** Locating newline characters (`\n`) and splitting strings into returned lines and remaining buffer tails.
  **Multi-FD Management (Bonus):** Tracking state for thousands of simultaneous file descriptors (`OPEN_MAX` / `1024`) using an array of static pointers.

---

## 🛠️ Technologies
* **Language:** C
* **Build System:** Makefile (for test builds / linking)
* **Version Control:** Git
* **Libraries & Headers:** `<unistd.h>` (for `read`), `<stdlib.h>` (for `malloc`/`free`), `<fcntl.h>` (for `open` in test mains)

---

## 🎯 Hard Skills
* **Static Variable Implementation:** Using static state to store unparsed data across function boundaries.
* **Low-Level File I/O:** Interfacing with OS file handles and handling partial reads.
* **Memory Leak Prevention:** Ensuring every allocated byte is freed, especially during error states or EOF.
* **Buffer Size Adaptability:** Writing code that behaves deterministically regardless of whether `BUFFER_SIZE` is set to `1`, `42`, or `1000000`.

---

## 🤝 Soft Skills
* **Code Modularization:** Splitting line-reading, string concatenation, and residual-buffer saving into distinct, single-responsibility functions.
* **Rigor & Edge Case Handling:** Handling invalid file descriptors (`fd < 0`), non-existent files, empty lines, EOF reached, allocation failures, and huge buffer sizes.
* **Norminette Compliance:** Adhering strictly to 42's coding standard constraints (e.g., maximum 25 lines per function, limit on local variables).

---

## 📁 Project Structure

```text
├── bonus
│   ├── get_next_line_bonus.c
│   ├── get_next_line_bonus.h
│   └── get_next_line_utils_bonus.c
└── mandatory
    ├── get_next_line.c
    ├── get_next_line.h
    ├── get_next_line_utils.c
    ├── main.c
    └── text.txt

```
