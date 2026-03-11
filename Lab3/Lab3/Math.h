#ifndef MATH_H
#define MATH_H

#include <stdarg.h>

class Math
{
public:
    // --- Adunare int ---
    static int Add(int a, int b);
    static int Add(int a, int b, int c);

    // --- Adunare double (returneaza int - truncheaza) ---
    static int Add(double a, double b);
    static int Add(double a, double b, double c);

    // --- Inmultire int ---
    static int Mul(int a, int b);
    static int Mul(int a, int b, int c);

    // --- Inmultire double (returneaza int - truncheaza) ---
    static int Mul(double a, double b);
    static int Mul(double a, double b, double c);

    // --- Suma variadic: Add(count, val1, val2, ...) ---
    static int Add(int count, ...);

    // --- Concatenare stringuri (aloca memorie noua) ---
    static char* Add(const char* s1, const char* s2);
};

#endif // MATH_H