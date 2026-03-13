#include "StudentCompare.h"
#include <string.h>

static int cmpFloat(float a, float b)
{
    if (a > b) return  1;
    if (a < b) return -1;
    return 0;
}

int compareByName(const Student& a, const Student& b)
{
    int r = strcmp(a.getName(), b.getName());
    if (r > 0) return  1;
    if (r < 0) return -1;
    return 0;
}

int compareByMath(const Student& a, const Student& b) { return cmpFloat(a.getMath(), b.getMath()); }
int compareByEnglish(const Student& a, const Student& b) { return cmpFloat(a.getEnglish(), b.getEnglish()); }
int compareByHistory(const Student& a, const Student& b) { return cmpFloat(a.getHistory(), b.getHistory()); }
int compareByAverage(const Student& a, const Student& b) { return cmpFloat(a.getAverage(), b.getAverage()); }