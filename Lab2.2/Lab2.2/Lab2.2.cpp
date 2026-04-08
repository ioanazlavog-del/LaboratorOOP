#include "Student.h"
#include "StudentCompare.h"
#include <stdio.h>

void printCmp(const char* label, int result, const Student& a, const Student& b)
{
    printf("[%-8s] ", label);
    if (result == 0) printf("%s == %s\n", a.getName(), b.getName());
    else if (result == 1) printf("%s >  %s\n", a.getName(), b.getName());
    else                   printf("%s <  %s\n", a.getName(), b.getName());
}

int main()
{
    Student s1, s2;
    s1.Init();
    s2.Init();

    s1.setName("Andrei Popescu");
    s1.setMath(9.5f);
    s1.setEnglish(8.0f);
    s1.setHistory(7.5f);

    s2.setName("Maria Ionescu");
    s2.setMath(8.0f);
    s2.setEnglish(9.5f);
    s2.setHistory(9.0f);

    printf("=== Studenti ===\n");
    s1.Print();
    s2.Print();

    printf("\n=== Getteri ===\n");
    printf("Numele lui s1:   %s\n", s1.getName());
    printf("Nota mate s1:    %.2f\n", s1.getMath());
    printf("Nota engleza s2: %.2f\n", s2.getEnglish());
    printf("Media s2:        %.2f\n", s2.getAverage());

    printf("\n=== Validare nota invalida ===\n");
    bool ok = s1.setMath(11.0f);
    printf("setMath(11.0) a returnat: %s\n", ok ? "true" : "false");

    printf("\n=== Comparatii ===\n");
    printCmp("Nume", compareByName(s1, s2), s1, s2);
    printCmp("Mate", compareByMath(s1, s2), s1, s2);
    printCmp("Engleza", compareByEnglish(s1, s2), s1, s2);
    printCmp("Istorie", compareByHistory(s1, s2), s1, s2);
    printCmp("Medie", compareByAverage(s1, s2), s1, s2);

    return 0;
}