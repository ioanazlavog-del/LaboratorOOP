#include "Canvas.h"
#include <stdio.h>
#include <stdlib.h>

Canvas::Canvas(int w, int h) : width(w), height(h)
{
    grid = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++)
        grid[i] = (char*)malloc(width * sizeof(char));
    Clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; i++)
        free(grid[i]);
    free(grid);
}

bool Canvas::inBounds(int x, int y) const
{
    return (x >= 0 && x < width && y >= 0 && y < height);
}

void Canvas::Clear()
{
    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            grid[row][col] = ' ';
}

void Canvas::Print()
{
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

    printf("+");
    for (int col = 0; col < width; col++) printf("-");
    printf("+\n");
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (inBounds(x, y))
        grid[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = -abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx + dy;

    while (true)
    {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 >= dy) { if (x1 == x2) break; err += dy; x1 += sx; }
        if (e2 <= dx) { if (y1 == y2) break; err += dx; y1 += sy; }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int x = left; x <= right; x++) { SetPoint(x, top, ch);   SetPoint(x, bottom, ch); }
    for (int y = top + 1; y < bottom; y++) { SetPoint(left, y, ch);  SetPoint(right, y, ch); }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; y++)
        for (int x = left; x <= right; x++)
            SetPoint(x, y, ch);
}

void Canvas::DrawCircle(int cx, int cy, int ray, char ch)
{
    int x = 0, y = ray, p = 1 - ray;

    while (x <= y)
    {
        SetPoint(cx + x, cy + y, ch); SetPoint(cx - x, cy + y, ch);
        SetPoint(cx + x, cy - y, ch); SetPoint(cx - x, cy - y, ch);
        SetPoint(cx + y, cy + x, ch); SetPoint(cx - y, cy + x, ch);
        SetPoint(cx + y, cy - x, ch); SetPoint(cx - y, cy - x, ch);
        x++;
        if (p < 0) p += 2 * x + 1;
        else { y--; p += 2 * (x - y) + 1; }
    }
}

void Canvas::FillCircle(int cx, int cy, int ray, char ch)
{
    int x = 0, y = ray, p = 1 - ray;

    while (x <= y)
    {
        for (int i = cx - x; i <= cx + x; i++) { SetPoint(i, cy + y, ch); SetPoint(i, cy - y, ch); }
        for (int i = cx - y; i <= cx + y; i++) { SetPoint(i, cy + x, ch); SetPoint(i, cy - x, ch); }
        x++;
        if (p < 0) p += 2 * x + 1;
        else { y--; p += 2 * (x - y) + 1; }
    }
}