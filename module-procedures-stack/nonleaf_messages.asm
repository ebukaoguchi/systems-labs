# nonleaf_messages.asm
#
# Worked example for SCIS 216 Lab 4, "Leaf, Non-Leaf & Stack
# Pointer / Register in MIPS": the same save / call / restore
# pattern, proven with messages instead of numbers.
#
# calculate (non-leaf) calls helper (leaf). main prints its
# "returned" message only if calculate returns correctly, which
# only happens if calculate saved $ra before calling helper and
# restored it afterwards.
#
# Expected output:
#   Inside helper function
#   Successfully returned to main!

        .data
returned: .asciiz "Successfully returned to main!\n"
inside:   .asciiz "Inside helper function\n"

        .text
        .globl main
main:
        jal  calculate

        # We only get here if calculate returns correctly
        li   $v0, 4
        la   $a0, returned
        syscall

        li   $v0, 10
        syscall

# Non-leaf function: calls helper, so it saves $ra first.
calculate:
        # Save return address to main
        addiu $sp, $sp, -4
        sw    $ra, 0($sp)

        # Call another function
        jal   helper

        # Restore return address to main
        lw    $ra, 0($sp)
        addiu $sp, $sp, 4

        # Return to main
        jr    $ra

# Leaf function: calls nothing, saves nothing.
helper:
        li   $v0, 4
        la   $a0, inside
        syscall
        jr   $ra
