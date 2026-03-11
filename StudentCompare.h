#ifndef STUDENT_H
#define STUDENT_H

class Student
{
    char name[100];
    float gradeMath;        // nota matematica  [1..10]
    float gradeEnglish;     // nota engleza      [1..10]
    float gradeHistory;     // nota istorie      [1..10]

    // Functie privata de validare nota
    bool isValidGrade(float g);

public:
    void Init();                        // initializeaza membrii

    // Setter / Getter - Nume
    void        setName(const char* n);
    const char* getName() const;

    // Setter / Getter - Matematica
    bool  setMath(float g);
    float getMath() const;

    // Setter / Getter - Engleza
    bool  setEnglish(float g);
    float getEnglish() const;

    // Setter / Getter - Istorie
    bool  setHistory(float g);
    float getHistory() const;

    // Media aritmetica a celor 3 note
    float getAverage() const;

    // Afisare rapida
    void Print() const;
};

#endif // STUDENT_H