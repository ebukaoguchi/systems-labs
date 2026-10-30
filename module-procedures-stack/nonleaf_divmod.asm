# nonleaf_divmod.asm
#
# Worked example for SCIS 216 Lab 4, "Leaf, Non-Leaf & Stack
# Pointer / Register in MIPS": a NON-LEAF procedure that must save
# and restore $ra because it calls another procedure.
#
# divmod(a, b) divides with div, takes the quotient from mflo into
# $v0 and the remainder from mfhi into $v1, and calls the leaf
# helper print_newline. Because jal overwrites $ra, divmod saves
# $ra on the stack before the call and restores it after.
#
# main does not print the quotient here. It prints 99, a sentinel:
# 99 can only appear if divmod returns to the correct place in
# main. (The newline before it is printed by the helper, from
# inside divmod.)
#
# Expected output:
#   (newline)
#   99

        .data
newline: .asciiz "\n"

        .text
        .globl main
main:
        li   $a0, 17
        li   $a1, 5
        jal  divmod

        # If divmod returns correctly, print 99
        li   $a0, 99
        li   $v0, 1
        syscall

        li   $v0, 10
        syscall

# divmod is NOT a leaf procedure: it calls print_newline,
# so it must save and restore $ra.
divmod:
        addiu $sp, $sp, -4        # allocate stack space
        sw    $ra, 0($sp)         # save return address

        div   $a0, $a1
        mflo  $v0                 # quotient
        mfhi  $v1                 # remainder

        jal   print_newline       # call another function

        lw    $ra, 0($sp)         # restore return address
        addiu $sp, $sp, 4         # deallocate stack space
        jr    $ra

# Leaf helper: prints a newline character.
print_newline:
        li    $a0, 10
        li    $v0, 11
        syscall
        jr    $ra
