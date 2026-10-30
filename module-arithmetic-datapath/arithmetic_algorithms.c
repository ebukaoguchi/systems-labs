/*
 * arithmetic_algorithms.c
 *
 * The two multiplication algorithms from "Inside the ALU", in C.
 * Both functions multiply non-negative 32-bit values and return the
 * full 64-bit product. Neither uses the * operator on the values
 * being multiplied: the point is to do what the hardware does.
 *
 * Build and run:
 *   gcc -std=c11 -Wall -Wextra -o arithmetic_algorithms arithmetic_algorithms.c
 *   ./arithmetic_algorithms
 */

#include <stdio.h>
#include <stdint.h>

/*
 * Basic multiplier (separate multiplicand, multiplier, product).
 *
 * Repeat until the multiplier is used up:
 *   - if the least significant bit of the multiplier is 1,
 *     add the multiplicand to the product;
 *   - shift the multiplicand left, shift the multiplier right.
 */
uint64_t multiply_basic(uint32_t multiplicand, uint32_t multiplier)
{
    uint64_t product = 0;
    uint64_t shifting_multiplicand = multiplicand;

    while (multiplier != 0) {
        if (multiplier & 1u) {
            product += shifting_multiplicand;
        }
        shifting_multiplicand <<= 1;
        multiplier >>= 1;
    }
    return product;
}

/*
 * Optimized multiplier (multiplier stored inside the product register).
 *
 * The 64-bit product starts with the multiplier in its lower half and
 * zero in its upper half. For each of the 32 multiplier bits:
 *   - if the least significant bit of the product is 1,
 *     add the multiplicand to the upper half;
 *   - shift the whole product right.
 * The multiplier bits are consumed as the product forms, so no
 * separate multiplier register is needed.
 */
uint64_t multiply_optimized(uint32_t multiplicand, uint32_t multiplier)
{
    uint64_t product = multiplier; /* upper 32 bits are 0 */

    for (int i = 0; i < 32; i++) {
        if (product & 1u) {
            product += (uint64_t)multiplicand << 32;
        }
        product >>= 1;
    }
    return product;
}

static int failures = 0;

static void check(const char *label, uint32_t a, uint32_t b)
{
    uint64_t expected = (uint64_t)a * b; /* the checker may use * */
    uint64_t basic = multiply_basic(a, b);
    uint64_t optimized = multiply_optimized(a, b);

    if (basic == expected && optimized == expected) {
        printf("%s: %u x %u = %llu  (basic and optimized agree)\n",
               label, a, b, (unsigned long long)expected);
    } else {
        printf("%s: %u x %u -> basic %llu, optimized %llu, expected %llu  FAIL\n",
               label, a, b,
               (unsigned long long)basic, (unsigned long long)optimized,
               (unsigned long long)expected);
        failures++;
    }
}

int main(void)
{
    check("Worked example", 6, 3);       /* the lecture example: 18 */
    check("Worksheet trace", 9, 6);      /* Part 2 of traces.md: 54 */
    check("Optimized trace", 10, 5);     /* Part 3 of traces.md: 50 */
    check("Edge case", 0, 12345);        /* multiplying by zero */
    check("Edge case", 1, 4000000000u);  /* product needs all 64 bits */
    check("Large values", 65535, 65535);

    if (failures == 0) {
        printf("All checks passed.\n");
        return 0;
    }
    printf("%d check(s) failed.\n", failures);
    return 1;
}
