#include "Canvas.h"
#include <stdio.h>

int main()
{
    Canvas c(60, 30);

    printf("=== SetPoint ===\n");
    c.SetPoint(5, 5, '*');
    c.Print();
    c.Clear();

    printf("\n=== DrawLine (Bresenham) ===\n");
    c.DrawLine(0, 0, 59, 29, '/');   // diagonala principala
    c.DrawLine(0, 29, 59, 0, '\\');  // diagonala secundara
    c.Print();
    c.Clear();

    printf("\n=== DrawRect ===\n");
    c.DrawRect(5, 3, 25, 12, '#');
    c.Print();
    c.Clear();

    printf("\n=== FillRect ===\n");
    c.FillRect(5, 3, 25, 12, '+');
    c.Print();
    c.Clear();

    printf("\n=== DrawCircle ===\n");
    c.DrawCircle(30, 14, 12, 'o');
    c.Print();
    c.Clear();

    printf("\n=== FillCircle ===\n");
    c.FillCircle(30, 14, 10, '@');
    c.Print();
    c.Clear();

    printf("\n=== Compozitie: casa ===\n");
    // Peretii casei
    c.FillRect(10, 15, 50, 28, '.');
    // Usa
    c.FillRect(27, 20, 33, 28, ' ');
    // Acoperisul (triunghi aproximat cu linii)
    c.DrawLine(10, 15, 30, 4, '^');
    c.DrawLine(50, 15, 30, 4, '^');
    c.DrawLine(10, 15, 50, 15, '^');
    // Ferestre
    c.FillRect(13, 17, 22, 24, 'X');
    c.FillRect(38, 17, 47, 24, 'X');
    c.Print();

    return 0;
}