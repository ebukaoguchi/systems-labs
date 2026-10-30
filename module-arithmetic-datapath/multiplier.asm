# multiplier.asm
#
# Basic shift-and-add multiplication in MIPS, for QtSpim (MIPS32).
# Computes multiplicand x multiplier for non-negative values and
# prints the product. This is the Part 2 algorithm from traces.md
# written as the hardware loop:
#
#   test the multiplier's least significant bit   -> andi
#   add the multiplicand if the bit is 1          -> add
#   shift the multiplicand left                   -> sll
#   shift the multiplier right                    -> srl
#
# Worked example as shipped: 6 x 3 = 18.
# Worksheet task: change the two .word values below to 9 and 6,
# reinitialize, and run again. The program should print 54.
#
# Note: this simple version assumes a non-negative multiplier.
# With a negative multiplier, srl fills with zeros from the left
# and the loop would run for all 32 bits of the shifted value.

        .data
multiplicand:   .word 6
multiplier:     .word 3
newline:        .asciiz "\n"

        .text
        .globl main
main:
        lw      $t0, multiplicand       # $t0 = multiplicand
        lw      $t1, multiplier         # $t1 = multiplier
        li      $t2, 0                  # $t2 = product = 0

LOOP:
        beq     $t1, $zero, DONE        # while (multiplier != 0)
        andi    $t3, $t1, 1             # $t3 = LSB of multiplier
        beq     $t3, $zero, SHIFT       # if LSB == 0, skip the add
        add     $t2, $t2, $t0           # product += multiplicand
SHIFT:
        sll     $t0, $t0, 1             # multiplicand <<= 1
        srl     $t1, $t1, 1             # multiplier >>= 1
        j       LOOP

DONE:
        move    $a0, $t2                # print the product
        li      $v0, 1
        syscall

        la      $a0, newline            # print a newline
        li      $v0, 4
        syscall

        li      $v0, 10                 # exit
        syscall
