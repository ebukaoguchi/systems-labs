# Systems Labs

**Laboratory modules for computer organization, architecture, and operating systems** — built, taught, and maintained by [Ebuka Philip Oguchi](https://ebukaoguchi.github.io/), Assistant Professor of Computer and Information Sciences, Spelman College.

These modules come from a single conviction: students learn systems by following one continuous pathway through the machine — *source code → compiler → ISA → datapath → memory hierarchy → operating system → security* — meeting each layer as something they can build, measure, and break. Every module names its stage on that pathway, states its objectives, and is staged in milestones with checkpoints, so another instructor can adopt a module whole or remix its parts.

## The modules

| # | Module | Pathway stage | Course | Status |
|---|--------|---------------|--------|--------|
| 1 | [Data That Survives the Program — Nested Loops and File Handling in C++](module-cpp-nested-loops-files/) | 01 · Source code | SCIS 123 C++ Programming, Lab 8 | Taught, Fall 2026 |
| 2 | [First Contact with the Machine — MIPS Assembly and Machine Code in QtSpim](module-qtspim-intro/) | 03 · ISA | SCIS 216 Computer Organization & Design, Lab 1 | Taught, Spring & Fall 2026 |
| 3 | [Logic Gates on a Breadboard — NOT, AND, OR with 74-Series ICs](module-logic-gates-breadboard/) | 04 · Datapath | SCIS 216, Lab 6 | Taught, Spring 2026 |
| 4 | [Build a MIPS Assembler — From Assembly to Machine Code](module-capstone-mips-assembler/) | 03 · ISA, in reverse | SCIS 216 capstone | Designed — first run end of Fall 2026 |
| 5 | [Inside the ALU — Adders, Multipliers, and Dividers](module-arithmetic-datapath/) | 04 · Datapath | SCIS 216 Computer Organization & Design | Lectures and in-class activities taught Fall 2026; packaged as a module |
| 6 | [Putting It All Together — The Student Grade Calculator](module-cpp-student-grade-calculator/) | 01 · Source code | SCIS 123 C++ Programming, Lab 6 | Taught, Fall 2026 |

Further modules from both courses (procedures and the stack, branching and control flow, register spilling, the C++ debugging lab, and the remaining SCIS 123 sequence) are being prepared for release.

**On the roadmap:** a GitHub-based workflow for SCIS 123 — a *Getting Started with GitHub* onboarding module, with students submitting their lab code through GitHub — designed for the course and scheduled to pilot in a future semester. It will be documented here once it has actually run in the classroom.

**Shared setup:** [Installing QtSpim for MIPS32](setup/qtspim-installation.md): the simulator installation guide (macOS, Windows, Linux) used by every MIPS module in this collection.

## Course context

The SCIS 216 modules accompany *Computer Organization and Design: The Hardware/Software Interface* (Patterson & Hennessy, 6th ed.), with assembly work in the QtSpim simulator. The SCIS 123 modules accompany an introductory C++ course. Each module lists the course learning objectives it serves and the week of the semester in which it runs.

## What is — and is not — here

This repository contains **instructor-authored, student-facing** material: module specifications, slide decks, worked examples, starter material, and exercise specifications with expected outputs.

It deliberately does **not** contain examination questions, assignment solutions, or answer keys, and no publisher or textbook slide content. Worked examples are the demonstrations taught live in class; graded exercises are published as specifications only.

## Adopting these modules

Instructors are welcome to adopt and remix modules with attribution. If you use one, a note about how it went — what worked, what broke — is the most valuable contribution you can make back; open an issue or get in touch via [my homepage](https://ebukaoguchi.github.io/).

## License

The materials in this repository are licensed under the [Creative Commons Attribution 4.0 International License (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/) — see the `LICENSE` file. You are free to share and adapt them, with attribution.
