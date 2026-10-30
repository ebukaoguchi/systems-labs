/*
 * float_bits.c
 *
 * Companion tool for the Systems Labs floating point module.
 * Prints the IEEE 754 single-precision bit pattern of a float,
 * broken into its sign, exponent, and fraction fields, so
 * students can check their hand conversions against an oracle.
 *
 * Build:  gcc -std=c11 -Wall -Wextra -o float_bits float_bits.c
 * Use:    ./float_bits 7.5
 *         sign = 0, exponent = 129 (unbiased 2),
 *         fraction = 0x700000, bits = 0x40F00000
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s <float>\n", argv[0]);
        return 1;
    }

    float value = strtof(argv[1], NULL);
    uint32_t bits;
    memcpy(&bits, &value, sizeof bits);

    unsigned sign = (bits >> 31) & 1u;
    unsigned exponent = (bits >> 23) & 0xFFu;
    unsigned fraction = bits & 0x7FFFFFu;

    printf("value    = %g\n", value);
    printf("bits     = 0x%08X\n", bits);
    printf("sign     = %u\n", sign);
    printf("exponent = %u (unbiased %d)\n", exponent, (int)exponent - 127);
    printf("fraction = 0x%06X\n", fraction);
    return 0;
}
