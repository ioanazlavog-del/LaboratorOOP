#ifndef CANVAS_H
#define CANVAS_H

class Canvas
{
    int   width;
    int   height;
    char** grid;   // matrice de char: grid[row][col]

    // Clip: verifica daca (x,y) este in interiorul canvas-ului
    bool inBounds(int x, int y) const;

public:
    Canvas(int width, int height);
    ~Canvas();  // elibereaza memoria alocata pentru grid

    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);  // Bresenham
    void Print() const;
    void Clear();
};

#endif // CANVAS_H