/* 
 * CS:APP Data Lab 
 * 
 * Allyson Morris 931109718
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */

 /* Use De Morgan’s law to get x & y with only ~ and | */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */

/* Extend the least significant bit across all bits */
int copyLSB(int x) {
   return (x << 31) >> 31;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */

/* Shift target byte to the right and mask with 0xFF */
int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xFF;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */

/* True if x and y are the same value */
int isEqual(int x, int y) {
  return !(x ^ y);
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

/* Build a mask of 1s between lowbit and highbit */
int bitMask(int highbit, int lowbit) {
    int all_ones = ~0;
    int high_mask = all_ones << highbit << 1; 
    int low_mask = (1 << lowbit) - 1;         
    return ~(high_mask | low_mask);  
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */

/* Reverse the order of all four bytes in x */
int reverseBytes(int x) {
    int byte0 = (x & 0xFF) << 24;
    int byte1 = (x & (0xFF << 8)) << 8;
    int byte2 = (x & (0xFF << 16)) >> 8;
    int byte3 = (x & (0xFF << 24)) >> 24;
    byte3 = byte3 & 0xFF;
    return byte0 | byte1 | byte2 | byte3;  
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */

/* Check if x is zero using sign bits of x and -x */
int bang(int x) {
    int neg_x = ~x + 1;
    int sign_bits = (x | neg_x) >> 31;
    return sign_bits + 1;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */

/* Return only the lowest 1-bit in x */
int leastBitPos(int x) {
    return x & (~x + 1);
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */

/* ~0 gives -1 in two’s complement */
int minusOne(void) {
    return ~0;  
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */

/* Make the largest two’s complement value */
int tmax(void) {
    return ~(1 << 31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

/* See if x fits in n bits after shifting */
int fitsBits(int x, int n) {
    int shift = 33 + (~n);
    int shifted = (x << shift) >> shift;
    return !(x ^ shifted);
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

/* Check if adding x and y causes overflow */
int addOK(int x, int y) {
    int sum = x + y;
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int sign_sum = sum >> 31;
    int overflow = ~(sign_x ^ sign_y) & (sign_x ^ sign_sum);
    return !overflow;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

/* Return 1 if x is greater than y */
int isGreater(int x, int y) {
    int sign_x = (x >> 31) & 1;
    int sign_y = (y >> 31) & 1;
    int sign_diff = sign_x ^ sign_y;
    int same_sign = !sign_diff;
    int diff = x + (~y + 1);
    int diff_sign = (diff >> 31) & 1;
    int result = (sign_diff & !sign_x) | (same_sign & !diff_sign & !!(diff));
    return result;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */

/* Return 1 if x is negative */
int isNegative(int x) {
    return (x >> 31) & 1;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */

/* Multiply by 5/8 and round toward zero */
int multFiveEighths(int x) {
    int times_five = (x << 2) + x;
    int sign = times_five >> 31;
    int bias = sign & 7;
    int result = (times_five + bias) >> 3;
    return result;
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */

/* Convert from sign-magnitude to two’s complement */
int sm2tc(int x) {
    int sign = x >> 31;
    int magnitude = x & ~(1 << 31);
    int tc_neg = ~magnitude + 1;
    return (sign & tc_neg) | (~sign & magnitude);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

/* Convert an int to its float bit representation */
unsigned float_i2f(int x) {
    unsigned sign, frac, exp;
    unsigned absx, round_bit;
    int shift;

    if (x == 0) return 0;

    sign = x & 0x80000000;
    absx = sign ? -x : x;

    shift = 31;
    while (!(absx & (1 << shift))) {
        shift--;
    }

    exp = shift + 127;
    absx = absx << (31 - shift);
    frac = (absx >> 8) & 0x7FFFFF;
    round_bit = absx & 0xFF;

    // Round to the nearest even
    if (round_bit > 128 || (round_bit == 128 && (frac & 1))) {
        frac++;
        if (frac >> 23) {
            frac &= 0x7FFFFF;
            exp++;
        }
    }

    return sign | (exp << 23) | frac;
}

