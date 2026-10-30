# Worksheets: Floating Point Representation and Arithmetic

Work each part **on paper first**. The self-check at the end gives final answers only, so you can verify your results without being handed the steps. The companion tool `float_bits.c` (build it, then run e.g. `./float_bits 7.5`) is the oracle for Parts A and B once you have committed to your own answers.

The format throughout is IEEE 754 **single precision**: 1 sign bit, 8 exponent bits with a bias of 127, and 23 fraction bits, with a hidden leading 1:

```
value = (-1)^S x 1.fraction x 2^(exponent - 127)
```

---

## Part A — Decimal to bits

Convert each decimal value to its 32-bit IEEE 754 pattern, giving the hexadecimal word and the three fields (sign, exponent field, fraction field).

| # | Value | Sign | Exponent field | Fraction field | Hex word |
|---|-------|------|----------------|----------------|----------|
| A1 | 5.75 | | | | |
| A2 | −12.25 | | | | |
| A3 | 0.1 | | | | |
| A4 | 100.5 | | | | |

For A3, keep going until you can see what the fraction field is doing, then answer in one sentence: why can 0.1 not be stored exactly?

## Part B — Bits to decimal

Decode each hexadecimal word into its decimal value, showing the three fields first.

| # | Hex word | Sign | Exponent field (unbiased) | Fraction | Value |
|---|----------|------|---------------------------|----------|-------|
| B1 | 0x3F800000 | | | | |
| B2 | 0xC0200000 | | | | |
| B3 | 0x42C80000 | | | | |
| B4 | 0xBF000000 | | | | |

## Part C — Floating point addition, by hand

Compute **7.5 + 2.25** the way the hardware does:

1. Write both operands in the form 1.fraction × 2^e.
   - 7.5 = ______ × 2^__
   - 2.25 = ______ × 2^__
2. Align the exponents: rewrite the smaller operand with the larger exponent. Its mantissa shifts ______ place(s) to the ______.
3. Add the mantissas: ______ + ______ = ______
4. Normalize the result into 1.fraction × 2^e form: ______ × 2^__
5. The final value is ______, and its IEEE 754 word is ______.

## Part D — Predict the program

`floating_point.asm` loads a = 7.5 and b = 2.5, then computes and prints. Predict **before running it**:

| Output line | Your prediction |
|---|---|
| Sum | |
| Difference | |
| Product | |
| Quotient | |
| Comparison message (which of the two messages?) | |
| Bit pattern printed for 7.5 | |

Then run it in QtSpim and reconcile any line that differs. (QtSpim prints floating point values in a fixed decimal format; judge the values, not the number of zeros.)

## Part E — Your turn

Change the program's data to a = 12.5 and b = 0.5. Predict all six output lines first, including the bit pattern of 12.5, then run and check.

---

## Self-check (final answers only)

- **A1:** 0x40B80000 · **A2:** 0xC1440000 · **A3:** 0x3DCCCCCD (the fraction is a repeating binary pattern, rounded at 23 bits; the stored value is approximately 0.10000000149, not exactly 0.1) · **A4:** 0x42C90000
- **B1:** 1.0 · **B2:** −2.5 · **B3:** 100.0 · **B4:** −0.5
- **C:** 1.875 × 2^2 and 1.125 × 2^1; align to 0.5625 × 2^2; sum 2.4375; normalize to 1.21875 × 2^3 = **9.75**, word **0x411C0000**
- **D:** 10.0 · 5.0 · 18.75 · 3.0 · "a is greater than b" · 40f00000
- **E:** 13.0 · 12.0 · 6.25 · 25.0 · "a is greater than b" · bit pattern of 12.5 = 41480000
