#include "NumberList.h"
#include <stdio.h>

int main()
{
    NumberList list;
    list.Init();

    list.Add(42);
    list.Add(7);
    list.Add(100);
    list.Add(3);
    list.Add(55);

    printf("Lista inainte de sortare:\n");
    list.Print();

    list.Sort();

    printf("Lista dupa sortare:\n");
    list.Print();

    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(9);

    bool ok = list.Add(999);
    if (!ok)
        printf("Lista este plina! Nu s-a putut adauga 999.\n");

    printf("Lista finala:\n");
    list.Print();

    return 0;
}