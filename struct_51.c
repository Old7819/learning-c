#include <stdio.h>

struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

// функция расчета площади прямоугольника
int area(struct Rect * p)
{
    return (p->rb.x - p->lt.x) * (p->lt.y - p->rb.y);
}

// сравниваем и возвращаем больший по площади прямоугольник
struct Rect * max(struct Rect * pa, struct Rect * pb)
{
    int a = area(pa);
    int b = area(pb);
    return (a > b) ? pa : pb;
}

int main() {
    struct Rect a = {{-7, 5}, {5, -3}};
    struct Rect b = {{1, 3}, {14, -4}};
    printf("Первый: (%d,%d) (%d,%d) %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y, area(&a));
    printf("Второй: (%d,%d) (%d,%d) %d\n", b.lt.x, b.lt.y, b.rb.x, b.rb.y, area(&b));
    printf("%d\n", area(max(&a, &b)));

    return 0;
}