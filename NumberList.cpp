#include "NumberList.h"
#include <stdio.h>

void NumberList::Init()
{
    count = 0;
    for (int i = 0; i < 10; i++)
        numbers[i] = 0;
}

bool NumberList::Add(int x)
{
    if (count >= 10)
        return false;
    numbers[count] = x;
    count++;
    return true;
}

void NumberList::Sort()
{
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (numbers[i] > numbers[j])
            {
                int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
}

void NumberList::Print()
{
    printf("[ ");
    for (int i = 0; i < count; i++)
    {
        printf("%d", numbers[i]);
        if (i < count - 1) printf(", ");
    }
    printf(" ]\n");
}