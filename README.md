# CPP Modules

```
 ██████╗ ██████╗ ██████╗ ███████╗    ███╗   ███╗ ██████╗ ██████╗ 
██╔════╝██╔═══██╗██╔══██╗██╔════╝    ████╗ ████║██╔═══██╗██╔══██╗
██║     ██║   ██║██████╔╝█████╗      ██╔████╔██║██║   ██║██████╔╝
██║     ██║   ██║██╔═══╝ ██╔══╝      ██║╚██╔╝██║██║   ██║██╔══██╗
╚██████╗╚██████╔╝██║     ███████╗    ██║ ╚═╝ ██║╚██████╔╝██║  ██║
 ╚═════╝ ╚═════╝ ╚═╝     ╚══════╝    ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝
```

A comprehensive collection of **C++ modules** from the **42 school** curriculum, covering the fundamentals of Object-Oriented Programming from basics to advanced STL algorithms.

![Language](https://img.shields.io/badge/Language-C++98-blue)
![Standard](https://img.shields.io/badge/Standard-C++98-green)
![School](https://img.shields.io/badge/School-42-black)

---

## Overview

This repository contains **10 modules** (`cpp00` - `cpp09`) with **34 exercises** covering the complete journey from C++ basics to advanced STL programming. All code compiles with `-Wall -Wextra -Werror` and targets the **C++98 standard**.

## Modules

| Module | Topic | Exercises | Focus |
|--------|-------|:---------:|-------|
| [**cpp00**](#cpp00---basics) | Basics | 2 | Namespaces, Classes, I/O |
| [**cpp01**](#cpp01---references--pointers) | References & Pointers | 7 | Memory, `new`/`delete`, References |
| [**cpp02**](#cpp02---orthodox-canonical-form) | OCF & Operators | 3 | Canonical Form, Operator Overloading |
| [**cpp03**](#cpp03---inheritance) | Inheritance | 3 | Class Hierarchies, Access Specifiers |
| [**cpp04**](#cpp04---polymorphism) | Polymorphism | 3 | Virtual Functions, Abstract Classes |
| [**cpp05**](#cpp05---exceptions) | Exceptions | 4 | Exception Handling, Factory Pattern |
| [**cpp06**](#cpp06---casts) | Casts | 3 | `static_cast`, `dynamic_cast`, RTTI |
| [**cpp07**](#cpp07---templates) | Templates | 3 | Function & Class Templates |
| [**cpp08**](#cpp08---stl) | STL Basics | 3 | Containers, Iterators, Algorithms |
| [**cpp09**](#cpp09---stl-advanced) | STL Advanced | 3 | Maps, Deques, Ford-Johnson Sort |

---

## cpp00 - Basics

> *Introduction to C++ syntax, classes, and I/O*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | Megaphone | `std::cout`, `std::string`, command-line args |
| ex01 | PhoneBook | Classes, constructors, `std::cin`/`std::cout`, member functions |

**Key concepts:** Namespaces, classes & instances, member attributes & functions, `this` pointer, initialization lists, `const`, accessors

---

## cpp01 - References & Pointers

> *Mastering memory management and references*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | Zombie | Stack vs heap allocation, constructors, destructors |
| ex01 | Zombie Horde | `new[]`/`delete[]`, dynamic arrays |
| ex02 | Pointers & References | Pointer/reference relationship |
| ex03 | Weapon | References vs pointers as class members |
| ex04 | Replace | File I/O, string manipulation |
| ex05 | Harl | Member function pointers |
| ex06 | Harl Filter | Switch fallthrough, log filtering |

**Key concepts:** `new`/`delete`, `std::ifstream`/`std::ofstream`, member function pointers, switch fallthrough

---

## cpp02 - Orthodox Canonical Form

> *Proper C++ class design and operator overloading*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | Fixed (basic) | Orthodox Canonical Form |
| ex01 | Fixed (constructors) | Type conversions, `operator<<` |
| ex02 | Fixed (operators) | All comparison/arithmetic/increment operators |

**Key concepts:** OCF (default ctor, copy ctor, copy assignment, destructor), fixed-point math, operator overloading, stream insertion

---

## cpp03 - Inheritance

> *Building class hierarchies*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | ClapTrap | Base class design, OCF |
| ex01 | ScavTrap | Public inheritance, constructor chaining, method overriding |
| ex02 | FragTrap | Growing inheritance hierarchy |

**Key concepts:** Public inheritance, `protected` access, constructor/destructor chaining, method overriding

---

## cpp04 - Polymorphism

> *The power of virtual functions and abstract classes*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | Animal | Virtual functions, virtual destructors |
| ex01 | Animal (Brain) | Deep copy, dynamic memory in inheritance |
| ex02 | Animal (Abstract) | Pure virtual functions, abstract classes |

**Key concepts:** `virtual` keyword, virtual destructors, pure virtual functions (`= 0`), abstract classes, deep vs shallow copy

---

## cpp05 - Exceptions

> *Robust error handling and design patterns*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | Bureaucrat | Custom exceptions, `std::exception` |
| ex01 | Form | Exception interaction between classes |
| ex02 | AForm | Abstract classes with pure virtual `execute()` |
| ex03 | Intern | Factory pattern |

**Key concepts:** `try`/`catch`/`throw`, custom exception classes, abstract classes, factory pattern, nested classes

---

## cpp06 - Casts

> *Type conversion and runtime type identification*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | ScalarConverter | `static_cast`, pseudo-literals, `strtod()` |
| ex01 | Serializer | `reinterpret_cast`, pointer serialization |
| ex02 | Identify | `dynamic_cast`, RTTI, pointer vs reference casts |

**Key concepts:** `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`, scalar types, serialization

---

## cpp07 - Templates

> *Generic programming with templates*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | Whatever | Function templates (`swap`, `min`, `max`) |
| ex01 | Iter | Templates with function pointers |
| ex02 | Array | Class templates, bounds-checked access |

**Key concepts:** Function templates, class templates, template instantiation, generic programming

---

## cpp08 - STL

> *Containers, iterators, and algorithms*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | Easy Find | `std::find`, iterator basics |
| ex01 | Span | `std::vector`, `std::sort`, `std::adjacent_difference` |
| ex02 | MutantStack | Container adaptors, exposing protected members |

**Key concepts:** `std::vector`, `std::list`, `std::stack`, iterators, STL algorithms

---

## cpp09 - STL Advanced

> *Advanced containers and real-world algorithms*

| Exercise | Name | Concepts |
|:--------:|------|----------|
| ex00 | Bitcoin Exchange | `std::map`, `lower_bound()`, date validation, CSV parsing |
| ex01 | RPN | `std::stack<int, std::list<int>>`, expression parsing |
| ex02 | PmergeMe | Ford-Johnson sort, `std::vector` vs `std::deque` timing |

**Key concepts:** `std::map`, `std::deque`, Ford-Johnson merge-insertion sort, Jacobsthal sequence, microsecond timing

---

## Build & Run

Each exercise contains its own `Makefile`. To build any exercise:

```bash
cd cpp00/ex00
make
./megaphone "hello world"
```

### Common Make Targets

| Target | Description |
|--------|-------------|
| `make` | Compile the program |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and binary |
| `make re` | Recompile everything |

---

## Project Structure

```
CPP_Modules/
├── cpp00/          # Basics
│   ├── ex00/       # Megaphone
│   └── ex01/       # PhoneBook
├── cpp01/          # References & Pointers
│   ├── ex00/       # Zombie
│   ├── ex01/       # Zombie Horde
│   ├── ex02/       # Pointers & References
│   ├── ex03/       # Weapon
│   ├── ex04/       # Replace
│   ├── ex05/       # Harl
│   └── ex06/       # Harl Filter
├── cpp02/          # OCF & Operators
│   ├── ex00/       # Fixed (basic)
│   ├── ex01/       # Fixed (constructors)
│   └── ex02/       # Fixed (operators)
├── cpp03/          # Inheritance
│   ├── ex00/       # ClapTrap
│   ├── ex01/       # ScavTrap
│   └── ex02/       # FragTrap
├── cpp04/          # Polymorphism
│   ├── ex00/       # Animal
│   ├── ex01/       # Animal (Brain)
│   └── ex02/       # Animal (Abstract)
├── cpp05/          # Exceptions
│   ├── ex00/       # Bureaucrat
│   ├── ex01/       # Form
│   ├── ex02/       # AForm
│   └── ex03/       # Intern
├── cpp06/          # Casts
│   ├── ex00/       # ScalarConverter
│   ├── ex01/       # Serializer
│   └── ex02/       # Identify
├── cpp07/          # Templates
│   ├── ex00/       # Whatever
│   ├── ex01/       # Iter
│   └── ex02/       # Array
├── cpp08/          # STL Basics
│   ├── ex00/       # Easy Find
│   ├── ex01/       # Span
│   └── ex02/       # MutantStack
└── cpp09/          # STL Advanced
    ├── ex00/       # Bitcoin Exchange
    ├── ex01/       # RPN
    └── ex02/       # PmergeMe
```

---

## Learning Path

```
┌─────────────────────────────────────────────────────────────────┐
│                        C++ Learning Path                        │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  cpp00 ──► cpp01 ──► cpp02 ──► cpp03 ──► cpp04                 │
│  Basics    Memory    OCF     Inherit    Poly                   │
│                                                                 │
│  cpp05 ──► cpp06 ──► cpp07 ──► cpp08 ──► cpp09                 │
│  Except    Casts    Templates  STL     STL Advanced            │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

---

## License

This project is part of the **42 school** curriculum.
