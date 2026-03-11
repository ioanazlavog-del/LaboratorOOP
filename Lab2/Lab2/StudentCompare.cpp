#include "Student.h"
#include <stdio.h>
#include <string.h>

// ---------- utilitare private ----------

bool Student::isValidGrade(float g)
{
    return (g >= 1.0f && g <= 10.0f);
}

// ---------- Init ----------

void Student::Init()
{
    name[0] = '\0';
    gradeMath = 1.0f;
    gradeEnglish = 1.0f;
    gradeHistory = 1.0f;
}

// ---------- Nume ----------

void Student::setName(const char* n)
{
    // strncpy copie cel mult 99 caractere si punem terminatorul manual
    strncpy(name, n, 99);
    name[99] = '\0';
}

const char* Student::getName() const
{
    return name;
}

// ---------- Matematica ----------

bool Student::setMath(float g)
{
    if (!isValidGrade(g)) return false;
    gradeMath = g;
    return true;
}

float Student::getMath() const { return gradeMath; }

// ---------- Engleza ----------

bool Student::setEnglish(float g)
{
    if (!isValidGrade(g)) return false;
    gradeEnglish = g;
    return true;
}

float Student::getEnglish() const { return gradeEnglish; }

// ---------- Istorie ----------

bool Student::setHistory(float g)
{
    if (!isValidGrade(g)) return false;
    gradeHistory = g;
    return true;
}

float Student::getHistory() const { return gradeHistory; }

// ---------- Medie ----------

float Student::getAverage() const
{
    return (gradeMath + gradeEnglish + gradeHistory) / 3.0f;
}

// ---------- Print ----------

void Student::Print() const
{
    printf("Student: %-20s | Mate: %.2f | Engleza: %.2f | Istorie: %.2f | Medie: %.2f\n",
        name, gradeMath, gradeEnglish, gradeHistory, getAverage());
}