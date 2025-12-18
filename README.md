# Basic-OS

A simple 32-bit x86 Operating System kernel built from scratch. 

## Prerequisites
To build and run this OS, you need a Linux environment (or WSL on Windows) with the following tools installed:

* **GCC** (Compiler)
* **NASM** (Assembler)
* **Make** (Build system)
* **QEMU** (x86 Emulator)

### Install Dependencies (Ubuntu/Debian/WSL)
Run the following command in your terminal:

```bash
sudo apt update
sudo apt install build-essential nasm qemu-system-x86
```

### How to run
1. Clone the repository
```bash
git clone [https://github.com/sanchana-arun/basic-os.git](https://github.com/sanchana-arun/basic-os.git)
cd basic-os
```

2. Build and Run: This command will compile the kernel, assemble the bootloader, create the OS image, and launch QEMU automatically.

```bash
make run
```

3. Clean Build Files: To remove all compiled binaries and object files:

```bash
make clean
```

## Project Structure
* `boot/`: Assembly source code for the bootloader and GDT.
* `kernel/`: C source code for the main kernel and drivers.
* `Makefile`: Build script to compile and link the OS image.