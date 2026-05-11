# Yocto Calculator Application

A custom Yocto layer containing calculator applications integrated into a Yocto Linux image.

This project demonstrates how to create and integrate custom applications into Yocto using BitBake recipes and Makefile-based builds.

---

# Project Overview

This project demonstrates:

* Creating a custom Yocto layer
* Writing BitBake recipes
* Building C++ applications in Yocto
* Using both direct compilation and Makefile-based builds
* Installing binaries into the target root filesystem
* Integrating packages into `core-image-sato`
* Running applications inside QEMU

---

# Project Structure

```text
meta-akanksha/
├── conf/
│   └── layer.conf
└── recipes-calculator/
    ├── calculator/
    │   ├── calculator_1.0.bb
    │   └── files/
    │       └── calculator.cpp
    │
└─ recipes-calculator-mkfile/
    ├── calculator/
    │   ├── mycal_1.0.bb
    │   └── files/
    │       └── calculator.cpp
            └── Makefile
```

---

# Recipes

## calculator

Basic BitBake recipe that directly compiles the calculator source using Yocto build tasks.

## mycal

Makefile-based BitBake recipe demonstrating:

* Custom Makefile integration
* `oe_runmake`
* Manual install steps
* External build system usage inside Yocto

---

# Features

The calculator supports:

* Addition
* Subtraction
* Multiplication
* Division
* Integer operations
* Floating-point operations

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

Add the package to `conf/local.conf`:

```conf
IMAGE_INSTALL:append = " mycal"
```

You can also use:

```conf
IMAGE_INSTALL:append = " calculator"
```

depending on which recipe you want to include.

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
calculator
```

or

```bash
/usr/bin/calculator
```

---

# Technologies Used

* Yocto Project
* BitBake
* Embedded Linux
* C++
* GNU Make
* QEMU

---

# Learning Outcomes

This project helped in understanding:

* Yocto layer structure
* BitBake recipes
* Makefile integration in Yocto
* Cross-compilation
* Root filesystem generation
* Package installation
* QEMU testing
* Embedded Linux development workflow

---

# Version History

| Version | Description                         |
| ------- | ----------------------------------- |
| v1.0    | Initial calculator BitBake recipe   |
| v1.1    | Added Makefile-based `mycal` recipe |

---
