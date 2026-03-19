#pragma warning(disable: 4996)
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <initializer_list>
#include <time.h>

void Sort::swapEl(int& a, int& b) { int t = a; a = b; b = t; }

int Sort::partition(int low, int high, bool asc)
{
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (asc ? (data[j] <= pivot) : (data[j] >= pivot))
        {
            i++; swapEl(data[i], data[j]);
        }
    swapEl(data[i + 1], data[high]);
    return i + 1;
}

void Sort::quickHelper(int low, int high, bool asc)
{
    if (low < high)
    {
        int pi = partition(low, high, asc);
        quickHelper(low, pi - 1, asc);
        quickHelper(pi + 1, high, asc);
    }
}

// Constructor 1: random
Sort::Sort(int n, int minVal, int maxVal)
{
    srand((unsigned int)time(NULL));
    count = n;
    data = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        data[i] = minVal + rand() % (maxVal - minVal + 1);
}

// Constructor 2: initializer list
Sort::Sort(std::initializer_list<int> list)
{
    count = (int)list.size();
    data = (int*)malloc(count * sizeof(int));
    int i = 0;
    for (int val : list)
        data[i++] = val;
}

// Constructor 3: din vector
Sort::Sort(int* arr, int n)
{
    count = n;
    data = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        data[i] = arr[i];
}

// Constructor 4: variadic
Sort::Sort(VariadicTag, int n, ...)
{
    count = n;
    data = (int*)malloc(count * sizeof(int));
    va_list args;
    va_start(args, n);
    for (int i = 0; i < count; i++)
        data[i] = va_arg(args, int);
    va_end(args);
}

// Constructor 5: din string
Sort::Sort(const char* str)
{
    count = 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',') count++;

    data = (int*)malloc(count * sizeof(int));
    char* buf = (char*)malloc(strlen(str) + 1);
    strcpy(buf, str);

    char* token = strtok(buf, ",");
    int i = 0;
    while (token != NULL)
    {
        data[i++] = atoi(token);
        token = strtok(NULL, ",");
    }
    free(buf);
}

Sort::~Sort() { free(data); }

void Sort::InsertSort(bool asc)
{
    for (int i = 1; i < count; i++)
    {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && (asc ? (data[j] > key) : (data[j] < key)))
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void Sort::QuickSort(bool asc)
{
    quickHelper(0, count - 1, asc);
}

void Sort::BubbleSort(bool asc)
{
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (asc ? (data[j] > data[j + 1]) : (data[j] < data[j + 1]))
                swapEl(data[j], data[j + 1]);
}

void Sort::Print()
{
    printf("[ ");
    for (int i = 0; i < count; i++)
    {
        printf("%d", data[i]);
        if (i < count - 1) printf(", ");
    }
    printf(" ]\n");
}

int Sort::GetElementsCount() { return count; }
int Sort::GetElementFromIndex(int index) { return (index >= 0 && index < count) ? data[index] : -1; }