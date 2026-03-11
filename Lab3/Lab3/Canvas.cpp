#include "Canvas.h"
#include <stdio.h>
#include <stdlib.h>  // malloc, free

// ============================================================
//  Constructor / Destructor
// ============================================================

Canvas::Canvas(int w, int h) : width(w), height(h)
{
    // Alocam un array de pointeri (cate un pointer per linie)
    grid = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++)
    {
        grid[i] = (char*)malloc(width * sizeof(char));
    }
    Clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; i++)
        free(grid[i]);
    free(grid);
}

// ============================================================
//  Utilitare private
// ============================================================

bool Canvas::inBounds(int x, int y) const
{
    return (x >= 0 && x < width && y >= 0 && y < height);
}

// ============================================================
//  Clear / Print
// ============================================================

void Canvas::Clear()
{
    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            grid[row][col] = ' ';  // pixelul gol = spatiu (ASCII 32)
}

void Canvas::Print() const
{
    // Borderul de sus
    printf("+");
    for (int col = 0; col < width; col++) printf("-");
    printf("+\n");

    for (int row = 0; row < height; row++)
    {
        printf("|");
        for (int col = 0; col < width; col++)
            printf("%c", grid[row][col]);
        printf("|\n");
    }

    // Borderul de jos
    printf("+");
    for (int col = 0; col < width; col++) printf("-");
    printf("+\n");
}

// ============================================================
//  SetPoint
// ============================================================

void Canvas::SetPoint(int x, int y, char ch)
{
    if (inBounds(x, y))
        grid[y][x] = ch;  // x = coloana, y = linia
}

// ============================================================
//  DrawLine  –  Algoritmul Bresenham
//
//  Bresenham deseneaza o linie intre (x1,y1) si (x2,y2)
//  folosind doar operatii pe intregi (fara float).
//
//  Idee: eroarea acumulata decide cand "urcam" sau nu pe axa
//  secundara.
// ============================================================

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = -abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;  // directia pe x
    int sy = (y1 < y2) ? 1 : -1;  // directia pe y
    int err = dx + dy;             // eroarea initiala

    while (true)
    {
        SetPoint(x1, y1, ch);

        if (x1 == x2 && y1 == y2) break;  // am ajuns la destinatie

        int e2 = 2 * err;

        if (e2 >= dy)   // pasim pe x
        {
            if (x1 == x2) break;
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)   // pasim pe y
        {
            if (y1 == y2) break;
            err += dx;
            y1 += sy;
        }
    }
}

// ============================================================
//  DrawRect  –  doar conturul dreptunghiului
// ============================================================

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    // Laturile orizontale
    for (int x = left; x <= right; x++)
    {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }
    // Laturile verticale
    for (int y = top; y <= bottom; y++)
    {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

// ============================================================
//  FillRect  –  dreptunghi umplut
// ============================================================

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; y++)
        for (int x = left; x <= right; x++)
            SetPoint(x, y, ch);
}

// ============================================================
//  DrawCircle  –  conturul cercului  (algoritmul Midpoint Circle)
//
//  Pornim din punctul (0, ray) si folosim un parametru de
//  decizie 'p' pentru a alege pixelul urmator.
//  Datorita simetriei cercului, desenam 8 octanti odata.
// ============================================================

void Canvas::DrawCircle(int cx, int cy, int ray, char ch)
{
    int x = 0;
    int y = ray;
    int p = 1 - ray;   // parametrul initial de decizie

    auto plot8 = [&](int px, int py)
        {
            SetPoint(cx + px, cy + py, ch);
            SetPoint(cx - px, cy + py, ch);
            SetPoint(cx + px, cy - py, ch);
            SetPoint(cx - px, cy - py, ch);
            SetPoint(cx + py, cy + px, ch);
            SetPoint(cx - py, cy + px, ch);
            SetPoint(cx + py, cy - px, ch);
            SetPoint(cx - py, cy - px, ch);
        };

    plot8(x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        plot8(x, y);
    }
}

// ============================================================
//  FillCircle  –  cerc umplut
//  Folosim aceeasi logica Midpoint, dar in loc de 8 puncte
//  desenam linii orizontale intre marginile cercului.
// ============================================================

void Canvas::FillCircle(int cx, int cy, int ray, char ch)
{
    int x = 0;
    int y = ray;
    int p = 1 - ray;

    auto hLine = [&](int lx, int rx, int fy)
        {
            for (int i = lx; i <= rx; i++)
                SetPoint(i, fy, ch);
        };

    auto fillSymmetric = [&](int px, int py)
        {
            hLine(cx - px, cx + px, cy + py);
            hLine(cx - px, cx + px, cy - py);
            hLine(cx - py, cx + py, cy + px);
            hLine(cx - py, cx + py, cy - px);
        };

    fillSymmetric(x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        fillSymmetric(x, y);
    }
}