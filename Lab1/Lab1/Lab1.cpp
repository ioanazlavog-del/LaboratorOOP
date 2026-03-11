// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// 1. 
#include <stdio.h>

// Functia noastra proprie care converteste un string la int (similar cu atoi)
int my_atoi(const char* str) {
    int result = 0;
    int i = 0;

    // Sarim peste spatii
    while (str[i] == ' ' || str[i] == '\t') i++;

    // Parcurgem cifrele si construim numarul
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int main() {
    FILE* f = fopen("in.txt", "r");  // Deschidem fisierul pentru citire
    if (f == NULL) {
        printf("Eroare: fisierul nu a putut fi deschis!\n");
        return 1;
    }

    char line[256];
    long long sum = 0;

    // Citim fisierul linie cu linie
    while (fgets(line, sizeof(line), f) != NULL) {
        sum += my_atoi(line);  // Convertim linia la numar si adunam
    }

    fclose(f);  // Inchidem fisierul
    printf("%lld\n", sum);
    return 0;
}

// 2. 
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 100

int word_len(const char* s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

// Comparare pentru sortare: dupa lungime DESC, apoi alfabetic ASC
void sort_words(char words[][MAX_LEN], int n) {
    char tmp[MAX_LEN];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int li = word_len(words[i]);
            int lj = word_len(words[j]);
            int swap = 0;

            if (li < lj) swap = 1;  // cel mai lung primul
            else if (li == lj && strcmp(words[i], words[j]) > 0) swap = 1; // alfabetic

            if (swap) {
                strcpy(tmp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tmp);
            }
        }
    }
}

int main() {
    char sentence[1000];
    char words[MAX_WORDS][MAX_LEN];
    int n = 0;

    printf("Introduceti o propozitie:\n");
    fgets(sentence, sizeof(sentence), stdin);

    // Splitam propozitia in cuvinte dupa spatii
    int i = 0;
    while (sentence[i] != '\0' && sentence[i] != '\n') {
        // Sarim peste spatii multiple
        while (sentence[i] == ' ') i++;
        if (sentence[i] == '\0' || sentence[i] == '\n') break;

        // Copiem cuvantul
        int j = 0;
        while (sentence[i] != ' ' && sentence[i] != '\0' && sentence[i] != '\n') {
            words[n][j++] = sentence[i++];
        }
        words[n][j] = '\0';
        n++;
    }

    sort_words(words, n);

    for (int k = 0; k < n; k++) {
        printf("%s\n", words[k]);
    }

    return 0;
}

// 3. 
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false;  // 0 si 1 nu sunt prime
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}

int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
    return 0;
}