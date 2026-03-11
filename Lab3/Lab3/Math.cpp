#include "Math.h"
#include <stdarg.h>
#include <stdlib.h>  // malloc
#include <string.h>  // strlen, strcpy, strcat

// ============================================================
//  Add - int
// ============================================================
int Math::Add(int a, int b) { return a + b; }
int Math::Add(int a, int b, int c) { return a + b + c; }

// ============================================================
//  Add - double  (rezultat trunchiat la int)
// ============================================================
int Math::Add(double a, double b) { return (int)(a + b); }
int Math::Add(double a, double b, double c) { return (int)(a + b + c); }

// ============================================================
//  Mul - int
// ============================================================
int Math::Mul(int a, int b) { return a * b; }
int Math::Mul(int a, int b, int c) { return a * b * c; }

// ============================================================
//  Mul - double  (rezultat trunchiat la int)
// ============================================================
int Math::Mul(double a, double b) { return (int)(a * b); }
int Math::Mul(double a, double b, double c) { return (int)(a * b * c); }

// ============================================================
//  Add variadic  – Add(int count, ...)
//  Primul argument = numarul de valori ce urmeaza
//  Exemplu: Math::Add(4, 10, 20, 30, 40)  =>  100
// ============================================================
int Math::Add(int count, ...)
{
    int sum = 0;
    va_list args;         // declaram lista de argumente variabile
    va_start(args, count); // initializam lista dupa parametrul 'count'

    for (int i = 0; i < count; i++)
        sum += va_arg(args, int); // extragem urmatorul int din lista

    va_end(args);          // curatam lista
    return sum;
}

// ============================================================
//  Add string  – concateneaza doua siruri; aloca memorie noua
//  Daca oricare dintre pointeri e nullptr, returneaza nullptr
// ============================================================
char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;

    // Alocam exact cat ne trebuie: len1 + len2 + 1 (terminator)
    int len = strlen(s1) + strlen(s2) + 1;
    char* result = (char*)malloc(len);

    if (result == nullptr)
        return nullptr;  // malloc a esuat

    strcpy(result, s1);   // copiem primul sir
    strcat(result, s2);   // concatenam al doilea sir
    return result;        // ATENTIE: apelatorul trebuie sa dea free()!
}