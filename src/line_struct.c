#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point a;    // начало отрезка
    Point b;    // конец отрезка
    float len;  // длина отрезка
} Line;

float distance(Point a, Point b)   // расстояние между точками
{
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    float len = sqrt(dx*dx + dy*dy);
    return len;
}

void scanLine(Line * t)
{
    scanf("%d%d%d%d", &t->a.x, &t->a.y, &t->b.x, &t->b.y);
}

void printLine(Line t)
{
    printf("%d %d %d %d %.3f", t.a.x, t.a.y, t.b.x, t.b.y, t.len);
}

void rotRLine(Line * t)
{
    int xn1, yn1, xn2, yn2;
    xn1 = t->a.y;
    yn1 = -t->a.x;
    xn2 = t->b.y;
    yn2 = -t->b.x;
    t->a.x = xn1;
    t->a.y = yn1;
    t->b.x = xn2;
    t->b.y = yn2;
    t->len = distance(t->a, t->b);
}

int main() {
    Line t;

    scanLine(&t);
    rotRLine(&t);
    printLine(t);

    return 0;
}