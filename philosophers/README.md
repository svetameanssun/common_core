# Philosophers

The goal of this project is to solve the classic **Dining Philosophers Problem** using C and POSIX threads. It provides a deep, hands-on understanding of concurrent programming, process/thread synchronization, race condition prevention, and deadlocks.

---

## 💡 Key Concepts
This project introduces the fundamentals of **multithreading** and **concurrency control**. It helps refine skills in managing shared memory resources across parallel threads, preventing data races using mutexes, calculating precise time intervals in milliseconds, and avoiding thread starvation and deadlocks.

---

## 🧠 Programming Concepts
* **Multithreading & Synchronization:** Creating and managing POSIX threads (`pthread_create`, `pthread_join`, `pthread_detach`) to run concurrent routines.
* **Mutexes & Critical Sections:** Using mutual exclusion locks (`pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`) to safely access shared data.
* **Time Management & High-Precision Sleep:** Implementing custom time-tracking algorithms using `gettimeofday()` to avoid execution drift and accurately monitor philosopher state transitions.
* **Deadlock & Starvation Avoidance:** Designing resource allocation strategies to ensure every thread gets access to forks without causing a permanent freeze or premature death.

---

## 🛠️ Tech Stack
* **Language:** C (C99 Standard)
* **Threading API:** POSIX Threads (`pthreads`)
* **Build System:** Makefile (`all`, `clean`, `fclean`, `re`)
* **Version Control:** Git
* **Debugging & Memory Analysis:** Valgrind (Helgrind / DRD), ThreadSanitizer (`-fsanitize=thread`)

---

## 🎯 Hard Skills
* **Thread Life Cycle Management:** Controlling parallel execution flows and cleanly detaching or joining threads upon exit.
* **Race Condition Prevention:** Securing shared variables (such as timestamps and meal counters) against concurrent read/write operations.
* **Precise Microsecond/Millisecond Timing:** Writing custom sleep functions to guarantee accurate timing despite OS scheduling delays.
* **Thread-Safe I/O Operations:** Protecting `printf` calls with dedicated mutexes to prevent overlapping, corrupted output logs.

---

## 🤝 Soft Skills
* **Concurrency Problem Solving:** Analyzing complex execution sequences to spot potential race conditions before writing code.
* **Memory & Resource Cleanup:** Ensuring zero memory leaks and properly destroying all initialized mutexes on termination.
* **Norminette & Code Precision:** Adhering strictly to 42's coding standard while structuring clean, maintainable C code.

---

## 📁 Project Structure

```text
.
├── include
│   └── philosophers.h
├── Makefile
└── src
    ├── getters.c
    ├── lock_routine.c
    ├── main.c
    ├── phil_utils.c
    ├── setters.c
    ├── start_supper.c
    ├── supervising.c
    └── time_print.c
