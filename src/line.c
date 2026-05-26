#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef struct {
    int x;
    int y;
} Point;


typedef struct {
    Point a;
    Point b;
} Line;


void printPoint(Point p)
{
    printf("(%d,%d) ", p.x, p.y);
}


void printLine(Line s)
{
    printf("(%d,%d) (%d,%d) \n", s.a.x, s.a.y, s.b.x, s.b.y);

}


float distance(Point p1, Point p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}


// получаем новую точку на dx от p
Point movePoint1(Point p, int dx)
{
    Point res = p;
    res.x += dx;
    return res;
}


void movePoint2(Point * p, int dx)
{
    p->x += dx;
}


// проверка на равенство точек
int is_equal(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}


int is_equalLine(Line p1, Line p2)
{
    return is_equal(p1.a, p2.a) && is_equal(p1.b, p2.b);
}


float lenght(Line p1)
{
    return distance(p1.a, p1.b);
}


// возвращаем новую точку
Point readPoint()
{
    Point res;
    scanf("%d%d", &res.x, &res.y);
    return res;
}


// изменяем уже существующую
void scanPoint(Point * p)
{
    int x, y;
    scanf("%d%d", &x, &y);
    p->x = x;
    p->y = y;
    // или короче scanf("%d%d", &p->x, &p->y);
}


Line readLine()
{
    Line res;
    res.a = readPoint();
    res.b = readPoint();
    return res;
}


void scanLine(Line * p)
{
    // scanLine(&p);
    scanPoint(&p->a);
    scanPoint(&p->b);
}


// возвращаем новый отрезок
Line moveLine1(Line s, int dx)
{
    Line res;
    res.a = movePoint1(s.a, dx);    // возвращает новую точку
    res.b = movePoint1(s.b, dx);
    return res;
}


// изменяем существующий отрезок
void moveLine2(Line * p, int dx)
{
    movePoint2( &p->a, dx);         // передаем указатель на точку
    movePoint2( &p->b, dx);
}


int main()
{
    Point p1 = {4, 3};
    Point p2 = {-4, -3};
    printPoint(p1);
    printPoint(p2);

    float d = distance(p1, p2);
    assert(d == 10);

    // из точки p (4,3) сделаем новую точку p_new (6,3)
    Point p_new = movePoint1(p1, 2);
    printPoint(p_new);
    Point exp_point = {6, 3};    // ожидаемый резудьтат (6,3)
    assert(is_equal(exp_point, p_new));

    // существующую точку p_new сдвинем еще раз и получим (8,3)
    exp_point.x += 2;    // ожидаемый результат (8,3)
    movePoint2(&p_new, 2);
    printPoint(p_new);    // (8,3)
    assert(is_equal(exp_point, p_new));

    p1 = readPoint();    // возвращаем новую точку, = копирует структуру
    scanPoint(&p2);    // заполняем значения полей уже существующей

    printPoint(p1);
    printPoint(p2);

    Line s = {{2, 3}, {5, 7}};
    printLine(s);
    printf("lenght=%.2f\n", lenght(s));
    assert(lenght(s) == 5);

    Line s_new = moveLine1(s, 3);
    printLine(s_new);
    Line exp_line = {{5, 3}, {8, 7}};
    assert(is_equalLine(s_new, exp_line));

    exp_line.a.x += 3;
    exp_line.b.x += 3;
    moveLine2(&s_new, 3);
    printLine(s_new);
    assert(is_equalLine(s_new, exp_line));

    Line s3 = readLine();
    printLine(s3);

    scanLine(&s3);
    printLine(s3);

    return 0;
}