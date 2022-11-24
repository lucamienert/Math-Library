#ifndef MATH_LIBRARY_H_
#define MATH_LIBRARY_H_

#pragma once

#ifdef USE_CONSTANTS
/**
 * The number e, also known as Euler's number, is a mathematical constant
 * 
 * - It is the base of the natural logarithms
 * 
 * - It is the limit of (1 + 1/n)^n as n approaches infinity, 
 *   an expression that arises in the study of compound interest
*/
const float E = 2.71828182845904523536;

/**
 * It returns the base-2 logarithm of E
*/
const float LOG2E = 1.44269504088896340736;

/**
 * It returns the base-10 logarithm of E
*/
const float LOG10E = 0.434294481903251827651;

/**
 * It returns the natual logarithm of 2
*/
const float LN2 = 0.693147180559945309417;

/**
 * It returns the natual logarithm of 10
*/
const float LN10 = 2.30258509299404568402;

/**
 * The square root of 2 is a positive real number that, 
 * when multiplied by itself, equals the number 2.
*/
const float SQRT2 = 1.41421356237309504880;

/**
 * The number π is a mathematical constant that is the ratio 
 * of a circle's circumference to its diameter.
*/
const float PI = 3.14159265358979323846;

/**
 * The number π is a mathematical constant that is the ratio 
 * of a circle's circumference to its diameter. PI_2 is the half of that.
*/
const float PI_2 = 1.57079632679489661923;

/**
 * The number π is a mathematical constant that is the ratio 
 * of a circle's circumference to its diameter. PI_4 is a quarter of that.
*/
const float PI_4 = 0.785398163397448309616;

#else

/**
 * The number e, also known as Euler's number, is a mathematical constant
 * 
 * - It is the base of the natural logarithms
 * 
 * - It is the limit of (1 + 1/n)^n as n approaches infinity, 
 *   an expression that arises in the study of compound interest
*/
#define E 2.71828182845904523536

/**
 * It returns the base-2 logarithm of E
*/
#define LOG2E 1.44269504088896340736

/**
 * It returns the base-10 logarithm of E
*/
#define LOG10E 0.434294481903251827651

/**
 * It returns the natual logarithm of 2
*/
#define LN2 0.693147180559945309417

/**
 * It returns the natual logarithm of 10
*/
#define LN10 2.30258509299404568402

/**
 * The square root of 2 is a positive real number that, 
 * when multiplied by itself, equals the number 2.
*/
#define SQRT2 1.41421356237309504880

/**
 * The number π is a mathematical constant that is the ratio 
 * of a circle's circumference to its diameter.
*/
#define PI 3.14159265358979323846

/**
 * The number π is a mathematical constant that is the ratio 
 * of a circle's circumference to its diameter. PI_2 is the half of that.
*/
#define PI_2 1.57079632679489661923

/**
 * The number π is a mathematical constant that is the ratio 
 * of a circle's circumference to its diameter. PI_4 is a quarter of that.
*/
#define PI_4 0.785398163397448309616

#endif

#define MIN(a, b) \
    a < b ? a : b

#define MAX(a, b) \
    a > b ? a : b

/**
 * The absolute value (or modulus) | x | of a real number x 
 * is the non-negative value of x without regard to its sign
 * 
 * @param {float} x
 * @returns {float}
*/
float abs(float x);

/**
 * Returns the sine of a number
 * 
 * @param {float} x
 * @returns {float} - A numeric expression that contains an angle measured in radians
*/
float sin(float x);

/**
 * Returns the cosine of a number
 * 
 * @param {float} x
 * @returns {float} - A numeric expression that contains an angle measured in radians
*/
float cos(float x);

/**
 * The ceil function always rounds up and returns the smaller integer 
 * greater than or equal to a given number
 * 
 * @param {float} x
 * @returns {float}
*/
float ceil(float x);

/**
 * The method returns E raised to the power of x (Ex). 
 * 'E' is the base of the natural system
 * 
 * @param {float} x
 * @returns {float}
*/
float exp(float x);

/**
 * The log method returns the natural logarithm of a number, 
 * or the logarithm of number to base
 * 
 * @param {float} x
 * @param {float} y
 * @returns {float}
*/
float log(float x, float y);

/**
 * The Method returns the value of x to the power of y (x^y)
 * 
 * @param {float} x
 * @param {float} y
 * @returns {float}
*/
float pow(float x, float y);

float abs(float x) {
    return x < 0.0 ? -x : x;
}

float sin(float x) {
    float result;
    asm("fsin" : "=t"(result) : "0"(x));
    return result;
}

float cos(float x) {
    return sin(x + PI / 2.0);
}

float ceil(float x)
{
    int n = (int) x;

    if (n >= x)
        return n;

    return n + 1;
}

float exp(float x)
{
    float x0 = abs(x);

    if (x == 0)
        return 1;

    int k = ceil((x0 / LN2) - 0.5);
    float p = 1 << k;
    float r = x0 - (k * LN2);
    float tn = 1;

    for (int i = 14; i > 0; i--)
        tn = tn * (r / i) + 1;

    p *= tn;

    if (x < 0)
        return 1 / p;

    return p;
}

float log(float x)
{
    int yi = y;
    int log2 = 0;
    float x, r;

    while (yi >>= 1)
        log2++;

    x = (float) (1 << log2);
    x = y / x;
    r = -1.7417939 + (2.8212026 + (-1.4699568 + (0.44717955 - 0.056570851 * x) * x) * x) * x;
    r += 0.69314718 * log2;

    return r;
}

float pow(float x, float y)
{
    return exp(x * log(y));
}

#endif