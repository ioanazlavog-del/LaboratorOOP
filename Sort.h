#pragma once
#include <initializer_list>
#include <stdarg.h>

struct VariadicTag {};

class Sort
{
    int* data;
    int  count;

    void swapEl(int& a, int& b);
    int  partition(int low, int high, bool asc);
    void quickHelper(int low, int high, bool asc);

public:
    Sort(int n, int minVal, int maxVal);
    Sort(std::initializer_list<int> list);
    Sort(int* arr, int n);
    Sort(VariadicTag, int n, ...);
    Sort(const char* str);
    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};