# Arbitrary Precision Calculator (APC)

A C-based command-line calculator that performs arithmetic operations (`+`, `-`, `*`, `/`) on arbitrarily large integers. Standard primitive data types like `long long` overflow when dealing with massive numbers, so this project uses doubly linked lists to store digits dynamically without size limits.

## Features

**Base-10 Linked List Storage:** Each node in a doubly linked list stores a single digit, allowing computation on numbers limited only by available system RAM.

**Basic Arithmetic Operations:** Supports Addition, Subtraction, Multiplication, and Division.

**Memory Safe:** Handles dynamic memory allocations and cleans up nodes upon completion or failure.

**Modular Code Structure:** Code base split logically into operations, helper utilities, and data structures.

## Directory Layout

```
APC/
├── dll/
│   └── dll.c           # Doubly linked list operations (insert, delete, print)
├── helper/
│   └── helper.c        # Utility functions (list comparison, leading zero removal)
├── include/
│   ├── apc.h           # Prototypes for APC operations
│   └── dll.h           # Structure definitions and dll prototypes
├── operations/
│   ├── add.c           # List addition logic
│   ├── subtract.c      # List subtraction logic
│   ├── multiply.c      # List multiplication logic
│   └── divide.c        # List division logic
├── .gitignore
├── Makefile            # Build configuration script
├── main.c              # Entry point and CLI parser
└── apc                 # Compiled executable output
```

## Getting Started

### Prerequisites

GCC Compiler

Make utility (or `mingw32-make` on Windows)

### Compilation

Build the executable using the provided Makefile:

Bash

```
make
```

To clear object files and rebuild from scratch:

Bash

```
make clean
```

## Usage

Run the compiled executable `apc` by passing two operands and an operator as command-line arguments:

Bash

```
./apc <Operand_1> <Operator> <Operand_2>
```

### Supported Operators

`+` : Addition

`-` : Subtraction

`'*'` : Multiplication

`/` : Division

### Examples

**Addition:**

Bash

```
./apc 123456789123456789 + 987654321987654321
```

**Subtraction:**

Bash

```
./apc 100000000000000000000 - 1
```

**Multiplication:**

Bash

```
./apc 999999999999 '*' 888888888888
```

**Division:**

Bash

```
./apc 1000000000000 / 500000
```