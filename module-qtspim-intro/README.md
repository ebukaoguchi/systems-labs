# Module: First Contact with the Machine — MIPS Assembly and Machine Code in QtSpim

**Pathway stage:** 03 · ISA (where assembly becomes machine code)
**Course:** SCIS 216 Computer Organization and Design — Lab 1 · **Semester placement:** Week 6, opening the MIPS unit
**Format:** One lab session · **Level:** First assembly-language lab

## Why this lab exists

Most first assembly labs stop at "run the program and watch the registers change." This one refuses to. Students run their first MIPS program in QtSpim — and then take it apart: they find the program counter, read the 32-bit machine code sitting at each address, and decode one instruction back into assembly by hand, field by field. The point is planted on day one and harvested all semester: *the bits are the program*, and assembly is just the human-readable spelling of them. This module is also the deliberate seed of the course capstone, in which students automate exactly this translation by writing an assembler.

## Learning objectives

By the end of this lab, students can:

- Load and run a MIPS program in QtSpim.
- Identify registers, memory, and instructions in the simulator's display, and say what each is for.
- Explain how data moves: memory → registers → ALU → memory — and why the CPU cannot compute directly on memory.
- Read the Text Segment: given an address, state its 32-bit machine code and its decoded assembly form.
- Decode an R-format instruction by hand into opcode, rs, rt, rd, shamt, and funct fields.

## Staged milestones

**Milestone 1 — Tour the simulator honestly.** The register panes (integer, floating-point), the Text and Data segments, the console — and the two blocks of code students did not write: QtSpim's startup code (loads argc/argv, calls `main`, shuts down — a miniature of what an operating system does) and kernel code (syscall and exception handling). Naming these now prevents the semester's most common confusion.

**Milestone 2 — First program: load, add, store.**

```asm
.data
num1: .word 28
num2: .word 228
sum:  .word 0
.text
.globl main
main:
    lw  $t0, num1       # load num1 into $t0
    lw  $t1, num2       # load num2 into $t1
    add $t2, $t1, $t0   # $t2 = num2 + num1
    sw  $t2, sum        # store result into sum
    li  $v0, 10         # exit
    syscall
```

Students trace it value by value: 28 and 228 into `$t0`/`$t1`, 256 out of the ALU into `$t2`, and back to memory at `sum`.

**Milestone 3 — Follow the program counter.** Normal flow: fetch at PC, execute, PC = PC + 4 (instructions are 4 bytes; memory is byte-addressed). Then the exceptions: a taken `beq`/`bne` replaces PC with the branch target; `j`/`jal` with the jump target. The PC is a "current page pointer" — usually next page, unless the program says otherwise.

**Milestone 4 — Meet the register file.** The special registers (PC, EPC, Cause, Status, HI/LO — the last pair waiting for the multiplication/division weeks) and the 32 general-purpose registers with their conventions: `$zero`, `$at`, `$v0–$v1`, `$a0–$a3`, `$t0–$t7`, `$s0–$s7`, `$gp`, `$sp`, `$ra`.

**Milestone 5 — Decode by hand.** Given `0x01285020` from the Text Segment, students split it into fields —

```
000000 | 01001 | 01000 | 01010 | 00000 | 100000
  op      rs      rt      rd     shamt   funct
  = 0     = $t1   = $t0   = $t2    = 0     = add
```

— and recover `add $t2, $t1, $t0`, using the deck's funct-code and opcode tables (R-format: add 0x20, sub 0x22, and 0x24, or 0x25, slt 0x2A, jr 0x08; I/J-format: lw 0x23, sw 0x2B, beq 0x04, bne 0x05, addi 0x08, j 0x02, jal 0x03). *Checkpoint: every student decodes one word unaided before leaving.*

## Deliverables

For an assigned program, students identify and submit:

- The program counter value at a specified step
- A memory address from the Text Segment
- The 32-bit machine code stored at that address
- The readable assembly instruction it decodes to — with the field breakdown shown

## Instructor notes

- Insist on the memory → register → ALU → memory narration for every trace. Students who can say *where a value lives* at each step stop writing assembly by pattern-matching.
- The HI/LO registers look pointless in Week 6; tell students to remember them — they return when multiplication and division hardware arrives (Weeks 10–11).
- Milestone 5 is not enrichment; it is the foundation of the end-of-semester assembler capstone. Students who decode fluently here write encoders there almost without noticing the direction reversed.

## Source deck

`Lab_1_QtSpim.pptx` — the full slide deck used in class accompanies this module in the repository.

---

*Part of the Systems Labs collection — laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
