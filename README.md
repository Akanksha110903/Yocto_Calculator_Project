# Yocto Calculator Application

A custom Yocto layer containing a simple C++ calculator application integrated into a Yocto Linux image.

## Project Overview

This project demonstrates:

- Creating a custom Yocto layer
- Writing a BitBake recipe
- Building a C++ application in Yocto
- Installing binaries into the target root filesystem
- Running the application inside QEMU
- Integrating the package into `core-image-sato`

---

# Project Structure

```text
meta-akanksha/
├── conf/
│   └── layer.conf
└── recipes-calculator/
    └── calculator/
        ├── calculator_1.0.bb
        └── files/
            └── calculator.cpp
```

---

# Features

The calculator supports:

- Addition
- Subtraction
- Multiplication
- Division
- Integer and floating-point operations

Example:

```bash
/usr/bin/calculator add 2 3
/usr/bin/calculator mul 2.5 3
```

---

# Yocto Build Steps

## 1. Add Layer

```bash
bitbake-layers add-layer ../layers/meta-akanksha
```

---

## 2. Add Package to Image

Add to `conf/local.conf`:

```bash
IMAGE_INSTALL:append = " calculator"
```

---

## 3. Build Image

```bash
bitbake core-image-sato
```

---

## 4. Run QEMU

```bash
runqemu qemux86-64
```

---

# Run Application

Inside QEMU:

```bash
/usr/bin/calculator
```

---

# Technologies Used

- Yocto Project
- BitBake
- Embedded Linux
- C++
- QEMU

---

# Learning Outcomes

This project helped in understanding:

- Yocto layer structure
- BitBake recipes
- Cross-compilation
- Root filesystem generation
- Package installation
- QEMU testing
