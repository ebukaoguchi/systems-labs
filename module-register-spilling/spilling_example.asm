# spilling_example.asm
#
# Worked example for SCIS 216 Lab 5, "Register Spilling in MIPS":
# a leaf procedure that spills a value to the stack in order to
# reuse its register.
#
#   int f(int a, int b, int c, int d) {
#       int x = a + b;
#       int y = c + d;
#       int z = x * y;
#       return z + x;      // x is needed again at the end
#   }
#
# x is computed into $t0, spilled to the stack, and $t0 is then
# reused for y. x is reloaded into $t1 before the final steps.
# With a = 2, b = 3, c = 4, d = 5:  x = 5, y = 9, z = 45,
# return 45 + 5 = 50.
#
# Expected output: 50

        .data
newline: .asciiz "\n"

        .text
        .globl main
main:
        li   $a0, 2
        li   $a1, 3
        li   $a2, 4
        li   $a3, 5
        jal  f

        # print value
        move $a0, $v0
        li   $v0, 1
        syscall

        # print newline
        la   $a0, newline
        li   $v0, 4
        syscall

        # exit
        li   $v0, 10
        syscall

f:
        add  $t0, $a0, $a1        # x = a + b

        addiu $sp, $sp, -4        # make space
        sw   $t0, 0($sp)          # spill x

        add  $t0, $a2, $a3        # reuse $t0 for y = c + d

        lw   $t1, 0($sp)          # reload x into $t1
        addiu $sp, $sp, 4         # pop space

        mul  $t2, $t1, $t0        # z = x * y
        add  $v0, $t2, $t1        # return z + x
        jr   $ra
