# example2_while_with_if.asm
#
# Worked Example 2 for SCIS 216 Lab 6, "Conditional Branching and
# Control Flow in MIPS": a while loop containing an if / else.
#
#   int i = 0;  int sum = 0;
#   while (i < 5) {
#       if (i % 2 == 0) sum = sum + i;
#       else            sum = sum - i;
#       i++;
#   }
#
# Register mapping: i -> $t0, sum -> $t1, loop limit -> $t2
# Trace: i=0 -> sum=0, i=1 -> sum=-1, i=2 -> sum=1, i=3 -> sum=-2,
#        i=4 -> sum=2
# Expected output: 2

        .data
newline: .asciiz "\n"

        .text
        .globl main
main:
        li   $t0, 0            # i = 0
        li   $t1, 0            # sum = 0
        li   $t2, 5            # loop limit

LOOP:
        # while (i < 5)
        slt  $t3, $t0, $t2
        beq  $t3, $zero, END

        # Check whether i is even (lowest bit 0)
        andi $t4, $t0, 1
        beq  $t4, $zero, EVEN

ODD:
        sub  $t1, $t1, $t0
        j    CONTINUE

EVEN:
        add  $t1, $t1, $t0

CONTINUE:
        addi $t0, $t0, 1
        j    LOOP

END:
        # Print sum
        move $a0, $t1
        li   $v0, 1
        syscall

        # Print newline
        la   $a0, newline
        li   $v0, 4
        syscall

        # Exit
        li   $v0, 10
        syscall
