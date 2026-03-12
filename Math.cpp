#pragma warning(disable: 4996)
#include "Math.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int Math::Add(int a, int b) { return a + b; }
int Math::Add(int a, int b, int c) { return a + b + c; }

int Math::Add(double a, double b) { return (int)(a + b); }
int Math::Add(double a, double b, double c) { return (int)(a + b + c); }

int Math::Mul(int a, int b) { return a * b; }
int Math::Mul(int a, int b, int c) { return a * b * c; }

int Math::Mul(double a, double b) { return (int)(a * b); }
int Math::Mul(double a, double b, double c) { return (int)(a * b * c); }

int Math::Add(int count, ...)
{
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
        sum += va_arg(args, int);
    va_end(args);
    return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;

    int len = (int)strlen(s1) + (int)strlen(s2) + 1;
    char* result = (char*)malloc(len);
    if (result == nullptr)
        return nullptr;

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}