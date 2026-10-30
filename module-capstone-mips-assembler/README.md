# Module (Capstone): Build a MIPS Assembler — From Assembly to Machine Code

**Pathway stage:** 03 · ISA, traversed in reverse — this time the students build the translator
**Course:** SCIS 216 Computer Organization and Design — end-of-semester synthesis project
**Semester placement:** Final weeks (after datapath and instruction execution, Weeks 13–14)
**Status:** *Designed — scheduled for the end of the current semester; this specification will be revised with classroom evidence after its first run.*

## Why this project exists

All semester, students have consumed translations: QtSpim turns their assembly into machine code, and in Lab 1 they decoded one machine word back into assembly by hand. The capstone reverses the direction and automates it: each student writes a small two-pass assembler that translates a real subset of MIPS assembly into the 32-bit machine code QtSpim would produce. It is the course's ideas combined in one artifact — instruction formats, register conventions, addressing, the program counter, and disciplined program design in a systems tool. Nothing in it is new; everything in it is connected. That is the point.

## The contract

The assembler accepts a `.asm` source file using the instruction subset below and emits one 32-bit machine word per instruction, in hexadecimal — the same words visible in QtSpim's Text Segment for the same program.

**R-format** (op = 0): `add`, `addu`, `sub`, `and`, `or`, `slt`, `sll`, `srl`, `jr`, `syscall`
**I-format:** `lw`, `sw`, `addi`, `andi`, `ori`, `lui`, `beq`, `bne`
**J-format:** `j`, `jal`
Plus: labels, comments (`#`), the `.text` directive, decimal and hexadecimal immediates, and `lw`/`sw` offset syntax such as `lw $t0, 4($sp)`.

These are exactly the instructions tabulated in the course's Lab 1 deck — the subset students have been reading all semester.

## Learning objectives

By completing the capstone, students demonstrate that they can:

- Encode R-, I-, and J-format instructions from their field layouts, including funct and opcode tables.
- Implement a two-pass design: a symbol table built in pass 1, code generation in pass 2.
- Compute PC-relative branch offsets and jump targets correctly — the program counter stops being a definition and becomes arithmetic they own.
- Verify a tool against an oracle: diff their assembler's output against QtSpim's Text Segment for the same source program.

## Staged milestones

**Milestone 1 — Parser and register map.** Tokenize source lines; strip comments; map every register name (`$t0`, `$sp`, `$ra`, …) to its number, and every mnemonic to its format. *Check: the tool prints a clean token stream for a sample program.*

**Milestone 2 — R-format encoder.** Assemble arithmetic instructions. The acceptance test is the word students decoded by hand in Lab 1: `add $t2, $t1, $t0` must emit `0x01285020`. *Check: a table of R-format cases, each verified against its hand-computed value.*

**Milestone 3 — I-format and memory instructions.** Immediates with sign extension; `lw`/`sw` offset(base) parsing. *Check: the Lab 1 load–add–store program assembles word-for-word identically to QtSpim.*

**Milestone 4 — Labels and control flow.** Two passes: record label addresses, then resolve `beq`/`bne` offsets ((target − (PC + 4)) / 4) and `j`/`jal` targets. *Check: a looping program with backward and forward branches assembles identically to QtSpim.*

**Milestone 5 — Verification harness and hardening.** Assemble every program the student wrote during the semester's labs; diff all outputs against QtSpim automatically; report any mismatch with the source line responsible. Decide and document the tool's behaviour on malformed input. *Check: the full corpus passes, and the diff report is empty.*

## Deliverables

- Assembler source code in C++ — the language of the pathway's first stage, whose file handling, strings, and maps are exactly the tools this project needs (a Python implementation is acceptable with the instructor's approval, declared in the design note)
- A test suite: `.asm` inputs with their expected machine-code outputs
- A one-page design note: the two-pass structure, the symbol table, and one encoding decision the student found genuinely tricky

## Instructor notes

- The implementation language is deliberate. An assembler is a text-processing program, and C++ gives students the strings, maps, and file input they learned in SCIS 123. Writing the assembler in MIPS assembly itself (self-hosting) is a different and much larger project; at this level it would bury the encoding ideas under string handling.
- Milestone 2's acceptance test deliberately reuses Lab 1's decoded word. Students recognise `0x01285020` — the capstone's first success is a callback to their first lab, and they feel the semester close its loop.
- The branch-offset milestone is where the class's Week 8 and Week 13 knowledge collides: students who truly understood PC = PC + 4 find (target − (PC+4))/4 obvious; students who memorised it find the bug immediately. Either outcome is instructive.
- QtSpim as oracle removes grading ambiguity: correctness is a diff, not an opinion. Reserve human grading for the design note.
- Scope discipline matters more than completeness: a correct small assembler beats an ambitious broken one. Extensions (pseudo-instructions such as `li` and `move`, `.data` layout) are explicitly bonus territory.

---

*Part of the Systems Labs collection — laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
