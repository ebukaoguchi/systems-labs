# nonleaf_spilling.asm
#
# Worked example for SCIS 216 Lab 5, "Register Spilling in MIPS":
# a NON-LEAF procedure that both saves $ra and spills a value,
# keeping the two saves in separate slots of one stack frame.
#
#   int g(int x, int y) { return x * y; }              // leaf
#   int f(int a, int b, int c, int d) {                // non-leaf
#       int x = a + b;
#       int y = c + d;
#       int z = g(x, y);
#       return z + x;
#   }
#
# f's frame is 8 bytes: $ra at 4($sp), spilled x at 0($sp).
# x must survive the call to g, so it lives on the stack while
# $a0 and $a1 are repurposed as g's arguments.
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

        # print result in $v0
        move $a0, $v0
        li   $v0, 1
        syscall

        # newline
        la   $a0, newline
        li   $v0, 4
        syscall

        # exit
        li   $v0, 10
        syscall

f:
        addiu $sp, $sp, -8
        sw    $ra, 4($sp)         # save $ra

        add   $t0, $a0, $a1       # x = a + b
        sw    $t0, 0($sp)         # spill x

        add   $t0, $a2, $a3       # y = c + d (reuse $t0)

        lw    $a0, 0($sp)         # $a0 = x (first argument for g)
        move  $a1, $t0            # $a1 = y (second argument)
        jal   g                   # $v0 = x * y

        lw    $t1, 0($sp)         # reload x
        add   $v0, $v0, $t1       # $v0 = x * y + x

        lw    $ra, 4($sp)         # restore $ra
        addiu $sp, $sp, 8
        jr    $ra

# g(x, y) = x * y  (leaf)
g:
        mul   $v0, $a0, $a1
        jr    $ra
