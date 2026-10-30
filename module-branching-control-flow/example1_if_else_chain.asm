# example1_if_else_chain.asm
#
# Worked Example 1 for SCIS 216 Lab 6, "Conditional Branching and
# Control Flow in MIPS": translate an if / else if / else chain.
#
#   int a = 5;  int b = 3;  int result;
#   if (a < b)       result = a + b;
#   else if (a == b) result = a * b;
#   else             result = a - b;
#
# Register mapping: a -> $s0, b -> $s1, result -> $s2
# Expected output: 2   (5 < 3 false, 5 == 3 false, so result = 5 - 3)

        .data
a:      .word 5
b:      .word 3
result: .word 0
newline: .asciiz "\n"

        .text
        .globl main
main:
        # Load a and b
        lw   $s0, a
        lw   $s1, b

        # if (a < b)
        slt  $t0, $s0, $s1
        bne  $t0, $zero, LESS

        # else if (a == b)
        beq  $s0, $s1, EQUAL

        # else: result = a - b
        sub  $s2, $s0, $s1
        j    STORE

LESS:
        add  $s2, $s0, $s1
        j    STORE

EQUAL:
        mul  $s2, $s0, $s1

STORE:
        # Store result
        sw   $s2, result

        # Print result
        move $a0, $s2
        li   $v0, 1
        syscall

        # Print newline
        la   $a0, newline
        li   $v0, 4
        syscall

        # Exit
        li   $v0, 10
        syscall
