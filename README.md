# Systems Labs

**Laboratory modules for computer organization, architecture, and operating systems**, built, taught, and maintained by [Ebuka Philip Oguchi](https://ebukaoguchi.github.io/), Assistant Professor of Computer and Information Sciences, Spelman College.

Eighteen modules for two courses: SCIS 123 (C++ Programming) and SCIS 216 (Computer Organization and Design). Each module is self-contained: a specification, the slide deck as taught, worked examples, and the exercises set in class. Students can follow their course path below. Instructors can adopt one module or a whole sequence.

The collection follows one pathway through the machine: source code, then the instruction set, then the datapath. Each module header names its stage on that pathway, its objectives, and what to submit.

## Start here

### SCIS 123, C++ Programming

Work through the labs in course order. Each lab assumes the ones before it.

1. [Find the Bugs — Debugging and Reading Code in C++](module-cpp-debugging/) (Lab 3)
2. [One Value, Four Bases — Number Systems in C++](module-cpp-number-systems/) (Lab 4)
3. [Putting It All Together — The Student Grade Calculator](module-cpp-student-grade-calculator/) (Lab 6)
4. [Data That Survives the Program — Nested Loops and File Handling in C++](module-cpp-nested-loops-files/) (Lab 8)
5. [Many Small Jobs, One Menu — User-Defined Functions in C++](module-cpp-functions/) (Lab 9)
6. [Store the Grid — Arrays and Nested Loops in C++](module-cpp-arrays/) (Lab 10)

### SCIS 216, Computer Organization and Design

Install QtSpim first, using the shared guide: [Installing QtSpim for MIPS32](setup/qtspim-installation.md). Every MIPS module uses it. Then:

1. [First Contact with the Machine — MIPS Assembly and Machine Code in QtSpim](module-qtspim-intro/) (Lab 1)
2. [Who Calls Whom — Leaf and Non-Leaf Procedures and the Stack](module-procedures-stack/) (Lab 4)
3. [When Registers Run Out — Register Spilling in MIPS](module-register-spilling/) (Lab 5; take it after Procedures and the Stack)
4. [Making Decisions — Conditional Branching and Control Flow in MIPS](module-branching-control-flow/) (Lab 6)
5. [Logic Gates on a Breadboard — NOT, AND, OR with 74-Series ICs](module-logic-gates-breadboard/)
6. [Inside the ALU — Adders, Multipliers, and Dividers](module-arithmetic-datapath/), then the four breadboard builds in build order: [The Half Adder](module-half-adder/), [The Full Adder](module-full-adder/), [The Half Subtractor](module-half-subtractor/), [The Full Subtractor](module-full-subtractor/)
7. [Numbers with Points — Floating Point Representation and Arithmetic](module-floating-point/) (companion to Inside the ALU)
8. [Build a MIPS Assembler — From Assembly to Machine Code](module-capstone-mips-assembler/) (capstone; take it last)

One numbering note: two modules carry the number Lab 6. Logic Gates on a Breadboard ran as Lab 6 in Spring 2026, and Conditional Branching ran as Lab 6 in Fall 2026. Each module header gives its semester.

## The modules

Modules 5 to 9 are the arithmetic datapath group. It opens with the lecture module *Inside the ALU* (module 5): its worksheet, C and MIPS arithmetic algorithms, and the multiplier and divider designs. Four breadboard builds follow (modules 6 to 9), climbing from a half adder to a full subtractor.

| # | Module | What you do | Course and lab | Status |
|---|--------|-------------|----------------|--------|
| 1 | [Data That Survives the Program — Nested Loops and File Handling in C++](module-cpp-nested-loops-files/) | Process data with nested loops; read and write files in C++ | SCIS 123, Lab 8 | Taught, Fall 2026 |
| 2 | [First Contact with the Machine — MIPS Assembly and Machine Code in QtSpim](module-qtspim-intro/) | Run a first MIPS program in QtSpim; decode machine code by hand | SCIS 216, Lab 1 | Taught, Spring and Fall 2026 |
| 3 | [Logic Gates on a Breadboard — NOT, AND, OR with 74-Series ICs](module-logic-gates-breadboard/) | Wire logic gates from 74-series chips and test them against their truth tables | SCIS 216, Lab 6 (Spring 2026) | Taught, Spring 2026 |
| 4 | [Build a MIPS Assembler — From Assembly to Machine Code](module-capstone-mips-assembler/) | Build a working MIPS assembler in C++ | SCIS 216 capstone | Designed; first run end of Fall 2026 |
| 5 | [Inside the ALU — Adders, Multipliers, and Dividers](module-arithmetic-datapath/) | Follow addition, multiplication, and division from gates to MIPS instructions, with trace worksheets | SCIS 216 lecture module | Taught, Fall 2026 |
| 6 | [The Half Adder — One XOR, One AND, and the First Column of Addition](module-half-adder/) | Build a one-bit adder on a breadboard | SCIS 216, datapath group | Built and taught, Fall 2026 |
| 7 | [The Full Adder — Two Half Adders, One Carry Chain](module-full-adder/) | Add a carry-in: two half adders and an OR gate | SCIS 216, datapath group | Built and taught, Fall 2026 |
| 8 | [The Half Subtractor — Difference and Borrow](module-half-subtractor/) | Build a one-bit subtractor on a breadboard | SCIS 216, datapath group | Built and taught, Fall 2026 |
| 9 | [The Full Subtractor — Subtraction with a Borrow-In](module-full-subtractor/) | Add a borrow-in: two half subtractors in series | SCIS 216, datapath group | Built and taught, Fall 2026 |
| 10 | [Putting It All Together — The Student Grade Calculator](module-cpp-student-grade-calculator/) | Combine input, arithmetic, and selection in one complete C++ program | SCIS 123, Lab 6 | Taught, Fall 2026 |
| 11 | [Making Decisions — Conditional Branching and Control Flow in MIPS](module-branching-control-flow/) | Translate if/else chains and while loops into MIPS branches and jumps | SCIS 216, Lab 6 (Fall 2026) | Taught, Fall 2026 |
| 12 | [Who Calls Whom — Leaf and Non-Leaf Procedures and the Stack](module-procedures-stack/) | Write leaf and non-leaf procedures; manage the stack and `$ra` | SCIS 216, Lab 4 | Taught, Fall 2026 |
| 13 | [When Registers Run Out — Register Spilling in MIPS](module-register-spilling/) | Save and reload values when a procedure runs out of registers | SCIS 216, Lab 5 | Taught, Fall 2026 |
| 14 | [Numbers with Points — Floating Point Representation and Arithmetic](module-floating-point/) | Read IEEE 754 bit patterns; trace floating-point arithmetic | SCIS 216, companion to Inside the ALU | Taught, Fall 2026 |
| 15 | [Find the Bugs — Debugging and Reading Code in C++](module-cpp-debugging/) | Find, classify, and fix syntax and logic errors in short C++ programs | SCIS 123, Lab 3 | Taught, Fall 2026 |
| 16 | [One Value, Four Bases — Number Systems in C++](module-cpp-number-systems/) | Convert values between binary, octal, decimal, and hexadecimal in C++ | SCIS 123, Lab 4 | Taught, Fall 2026 |
| 17 | [Many Small Jobs, One Menu — User-Defined Functions in C++](module-cpp-functions/) | Split a menu-driven calculator into small user-defined functions | SCIS 123, Lab 9 | Taught, Fall 2026 |
| 18 | [Store the Grid — Arrays and Nested Loops in C++](module-cpp-arrays/) | Store and process grids with arrays and nested loops | SCIS 123, Lab 10 | Taught, Fall 2026 |

More modules are in preparation, including the remaining SCIS 123 sequence.

**On the roadmap:** a GitHub-based workflow for SCIS 123, a *Getting Started with GitHub* onboarding module with students submitting their lab code through GitHub, designed for the course and scheduled to pilot in a future semester. It will be documented here once it has actually run in the classroom.

**Companion site:** [From Gates to Systems](https://ebukaoguchi.github.io/gates-to-systems/) is the interactive companion to these modules. Every circuit there runs in the browser, with switches to flip and truth tables that follow the inputs.

## Course context

The SCIS 216 modules accompany *Computer Organization and Design: The Hardware/Software Interface* (Patterson & Hennessy, 6th ed.), with assembly work in the QtSpim simulator. The SCIS 123 modules accompany an introductory C++ course. Each module lists the course learning objectives it serves and the week of the semester in which it runs.

## What is, and is not, here

This repository contains **instructor-authored, student-facing** material: module specifications, slide decks, worked examples, starter material, and exercise specifications with expected outputs.

It deliberately does **not** contain examination questions, assignment solutions, or answer keys, and no publisher or textbook slide content. Worked examples are the demonstrations taught live in class; graded exercises are published as specifications only.

## Adopting these modules

Instructors are welcome to adopt and remix modules with attribution. If you use one, a note about how it went, what worked and what broke, is the most valuable contribution you can make back; open an issue or get in touch via [my homepage](https://ebukaoguchi.github.io/).

## License

The materials in this repository are licensed under the [Creative Commons Attribution 4.0 International License (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/); see the `LICENSE` file. You are free to share and adapt them, with attribution.
