#include "Sort.h"
#include <stdio.h>

int main()
{
    printf("=== Constructor 1: random (10 elemente, 1-100) ===\n");
    Sort s1(10, 1, 100);
    printf("Nesortate:       "); s1.Print();
    s1.BubbleSort(true);
    printf("BubbleSort ASC:  "); s1.Print();
    s1.BubbleSort(false);
    printf("BubbleSort DESC: "); s1.Print();

    printf("\n=== Constructor 2: initializer list {50,20,80,10,60} ===\n");
    Sort s2 = { 50, 20, 80, 10, 60 };
    printf("Nesortate:       "); s2.Print();
    s2.InsertSort(true);
    printf("InsertSort ASC:  "); s2.Print();
    s2.InsertSort(false);
    printf("InsertSort DESC: "); s2.Print();

    printf("\n=== Constructor 3: din vector ===\n");
    int arr[] = { 9, 3, 7, 1, 5, 8, 2 };
    Sort s3(arr, 7);
    printf("Nesortate:       "); s3.Print();
    s3.QuickSort(true);
    printf("QuickSort ASC:   "); s3.Print();
    s3.QuickSort(false);
    printf("QuickSort DESC:  "); s3.Print();

    printf("\n=== Constructor 4: variadic ===\n");
    Sort s4(VariadicTag{}, 6, 30, 10, 50, 20, 40, 60);
    printf("Nesortate:       "); s4.Print();
    s4.BubbleSort(true);
    printf("BubbleSort ASC:  "); s4.Print();

    printf("\n=== Constructor 5: string \"10,40,100,5,70\" ===\n");
    Sort s5("10,40,100,5,70");
    printf("Nesortate:       "); s5.Print();
    s5.InsertSort(true);
    printf("InsertSort ASC:  "); s5.Print();

    printf("\n=== Getteri ===\n");
    printf("Count:           %d\n", s5.GetElementsCount());
    printf("Element[0]:      %d\n", s5.GetElementFromIndex(0));
    printf("Element[2]:      %d\n", s5.GetElementFromIndex(2));

    return 0;
}