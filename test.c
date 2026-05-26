#include <stdio.h>

struct Point {
    int x;
    int y;
}; 
   
struct Rect {
    struct Point lt;    // координаты левой верхней вершины
    struct Point rb;    // координаты правой нижней вершины
}; 

void move(struct Rect * p, int dx) {
    p->lt.x += dx;
    p->rb.x += dx;
}

int main() {
    struct Rect a;
    scanf("%d%d%d%d", &a.lt.x, &a.lt.y, &a.rb.x, &a.rb.y);
    int dx;
    scanf("%d", &dx);
    printf("%d %d %d %d + %d = ", a.lt.x, a.lt.y, a.rb.x, a.rb.y, dx);
    move(&a, dx);
    printf("%d %d %d %d \n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    return 0;
}