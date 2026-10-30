# division.asm
#
# MIPS built-in division and the HI/LO registers, for QtSpim (MIPS32).
#
# The div instruction does not write an ordinary register. It leaves
#   the quotient  in LO   (copy it out with mflo)
#   the remainder in HI   (copy it out with mfhi)
#
# MIPS performs no divide-by-zero check: the result is undefined if
# the divisor is 0, so software must test the divisor first. The beq
# below is that test. Change the divisor to 0, reinitialize, and run
# to see the guard work; div is never executed.
#
# Worked example as shipped: 17 / 5 -> Quotient = 3, Remainder = 2.
# Worksheet task: change the values to 43 and 7. Expected output:
# Quotient = 6, Remainder = 1.

        .data
dividend:       .word 17
divisor:        .word 5
quotient_msg:   .asciiz "Quotient = "
remainder_msg:  .asciiz "\nRemainder = "
error_msg:      .asciiz "Error: divide by zero\n"
newline:        .asciiz "\n"

        .text
        .globl main
main:
        lw      $t0, dividend           # $t0 = dividend
        lw      $t1, divisor            # $t1 = divisor

        beq     $t1, $zero, DIV_BY_ZERO # software divide-by-zero check

        div     $t0, $t1                # LO = quotient, HI = remainder
        mflo    $s0                     # $s0 = quotient
        mfhi    $s1                     # $s1 = remainder

        la      $a0, quotient_msg       # print "Quotient = "
        li      $v0, 4
        syscall

        move    $a0, $s0                # print the quotient
        li      $v0, 1
        syscall

        la      $a0, remainder_msg      # print "\nRemainder = "
        li      $v0, 4
        syscall

        move    $a0, $s1                # print the remainder
        li      $v0, 1
        syscall

        la      $a0, newline            # print a newline
        li      $v0, 4
        syscall

        j       DONE

DIV_BY_ZERO:
        la      $a0, error_msg          # print the error message
        li      $v0, 4
        syscall

DONE:
        li      $v0, 10                 # exit
        syscall
