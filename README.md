# Custom RTOS

A lightweight educational **Real-Time Operating System (RTOS)** designed to explore low-level OS concepts in an embedded systems context, including scheduling, context switching, and hardware interaction.

This project follows a **layered architecture**, separating hardware, kernel, and application logic.

---

## 🏗️ Architecture Overview

The system is divided into clear layers:

* **Boot Layer (`boot/`)**

  * Startup code and system initialization
  * Stack setup and entry point configuration

* **Hardware Abstraction Layer (`hw/`)**

  * Low-level drivers and hardware interfaces
  * Timer and interrupt configuration

* **Kernel Layer (`rtos/`)**

  * Task scheduler (preemptive)
  * Context switching
  * Task control structures
  * Synchronization primitives (basic)

* **Application Layer (`app/`)**

  * User-defined tasks
  * Demonstration programs

---

## 🚀 Features

* Preemptive priority-based scheduler
* Task creation and lifecycle management
* Context switching (interrupt + software driven)
* Configurable system tick (timer-based)
* Basic synchronization primitives (extensible)
* Custom memory layout via linker script

---

## 📁 Repository Structure

```text
.
├── app/        # Application tasks and demos
├── boot/       # Startup code and system initialization
├── hw/         # Hardware abstraction and drivers
├── rtos/       # Core RTOS kernel
├── Makefile    # Build configuration
├── linker.ld   # Memory layout definition
```

---

## ⚙️ Build

```bash
make
```

### Requirements

* GCC or appropriate cross-compiler (e.g., `arm-none-eabi-gcc`)
* Make

---

## ▶️ Execution

Depending on your target:

### Emulator (recommended for testing)

```bash
qemu-system-<arch> -kernel output.elf
```

### Hardware

Flash the generated binary using your platform-specific toolchain.

---

## ⚙️ Configuration

System-level configurations such as:

* Tick frequency
* Stack sizes
* Task limits

are defined within the kernel and configuration headers.

---

## 🧠 Key Concepts Demonstrated

* Preemptive multitasking
* Interrupt-driven scheduling
* Context switching at register level
* Memory layout control via linker scripts
* Hardware-software interaction

---

## 📌 Example Workflow

1. System boots via `boot/`
2. Hardware initialized in `hw/`
3. Scheduler starts in `rtos/`
4. Tasks from `app/` are executed

---

## 🔧 Future Enhancements

* Full semaphore/mutex implementation
* Priority inversion handling
* Dynamic memory management
* Debugging/tracing support
* Multi-core support (advanced)

---

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Commit changes
4. Open a Pull Request

---

## 👤 Author

Educational RTOS project focused on embedded systems and OS internals.
