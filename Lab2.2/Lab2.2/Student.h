#pragma once

class Student
{
    char  name[100];
    float gradeMath;
    float gradeEnglish;
    float gradeHistory;

    bool isValidGrade(float g);

public:
    void Init();

    void        setName(const char* n);
    const char* getName() const;

    bool  setMath(float g);
    float getMath() const;

    bool  setEnglish(float g);
    float getEnglish() const;

    bool  setHistory(float g);
    float getHistory() const;

    float getAverage() const;
    void  Print() const;
};