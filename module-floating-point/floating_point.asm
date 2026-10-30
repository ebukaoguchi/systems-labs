# floating_point.asm
#
# Worked example for the Systems Labs floating point module:
# single-precision arithmetic in QtSpim using coprocessor 1.
#
# Computes, for a = 7.5 and b = 2.5:
#   a + b = 10.0      a - b = 5.0
#   a * b = 18.75     a / b = 3.0
# then compares the two values (c.lt.s + bc1t), and finally prints
# the raw IEEE 754 bit pattern of 7.5 by moving it to an integer
# register (mfc1) and printing it in hexadecimal (syscall 34):
#   bits of 7.5 = 40f00000
#
# QtSpim prints floats with syscall 2 in its own fixed format;
# the values are what matter.

        .data
a:      .float 7.5
b:      .float 2.5
s_sum:  .asciiz "7.5 + 2.5 = "
s_diff: .asciiz "7.5 - 2.5 = "
s_prod: .asciiz "7.5 * 2.5 = "
s_quot: .asciiz "7.5 / 2.5 = "
s_bits: .asciiz "bits of 7.5 = "
msg_gt: .asciiz "a is greater than b\n"
msg_le: .asciiz "a is not greater than b\n"
newline: .asciiz "\n"

        .text
        .globl main
main:
        lwc1  $f0, a              # $f0 = a = 7.5
        lwc1  $f2, b              # $f2 = b = 2.5

        # --- sum ---
        la    $a0, s_sum
        li    $v0, 4
        syscall
        add.s $f4, $f0, $f2
        mov.s $f12, $f4
        li    $v0, 2
        syscall
        la    $a0, newline
        li    $v0, 4
        syscall

        # --- difference ---
        la    $a0, s_diff
        li    $v0, 4
        syscall
        sub.s $f6, $f0, $f2
        mov.s $f12, $f6
        li    $v0, 2
        syscall
        la    $a0, newline
        li    $v0, 4
        syscall

        # --- product ---
        la    $a0, s_prod
        li    $v0, 4
        syscall
        mul.s $f8, $f0, $f2
        mov.s $f12, $f8
        li    $v0, 2
        syscall
        la    $a0, newline
        li    $v0, 4
        syscall

        # --- quotient ---
        la    $a0, s_quot
        li    $v0, 4
        syscall
        div.s $f10, $f0, $f2
        mov.s $f12, $f10
        li    $v0, 2
        syscall
        la    $a0, newline
        li    $v0, 4
        syscall

        # --- comparison: is b < a? ---
        c.lt.s $f2, $f0           # set FP condition if b < a
        bc1t  GREATER
        la    $a0, msg_le
        li    $v0, 4
        syscall
        j     BITS
GREATER:
        la    $a0, msg_gt
        li    $v0, 4
        syscall

BITS:
        # --- the representation, as an integer ---
        la    $a0, s_bits
        li    $v0, 4
        syscall
        mfc1  $a0, $f0            # raw bits of 7.5 into $a0
        li    $v0, 34             # print integer in hexadecimal
        syscall
        la    $a0, newline
        li    $v0, 4
        syscall

        li    $v0, 10
        syscall
