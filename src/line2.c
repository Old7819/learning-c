#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;  

void printPoint(Point p)
{
    printf("(%d,%d) ", p.x, p.y);
}

float distance(Point p1, Point p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Получаем новую точку на dx от p.
Point movePoint1(Point p, int dx)
{
    Point res = p;      // новая точка res из старой p
    res.x += dx;
    return res;         // вернули (откопировали значение) новой точки
}

void movePoint2(Point * p, int dx)
{
    p->x += dx;
}

int is_equal(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}


int main()
{
    Point p1 = {4, 3};
    Point p2 = {-4, -3};
    printPoint(p1);     // (4,3)
    printPoint(p2);     // (-4,-3)

    float d = distance(p1, p2);

    Point p_new = movePoint1(p1, 2);    // 6, 3
    printPoint(p_new);
    Point exp_point = {6, 3};           // ожидаемый результат (6,3)


    exp_point.x += 2;                   // ожидаемый результат (8,3)
    movePoint2(&p_new, 2);
    printPoint(p_new);                  // 8, 3

    return 0;
}