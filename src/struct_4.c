#include <stdio.h>

struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

// проверяем пересекаются ли два прямоугольника
int is_crossed(struct Rect a, struct Rect b)
{
    if ((a.rb.x < b.lt.x) || (b.rb.x < a.lt.x)) {
        return 0;
    } else if ((a.lt.y < b.rb.y) || (b.lt.y < a.rb.y)) {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    int num;
    struct Rect a = {{-7, 8}, {12, 5}};
    struct Rect b = {{1, 9}, {14, 3}};
    struct Rect c = {{-7, 8}, {12, 5}};
    struct Rect d = {{13, 9}, {14, 3}};
    struct Rect f = {{-7, 8}, {12, 5}};
    struct Rect z = {{-20, 9}, {-14, 3}};
    num = is_crossed(a, b);
    printf("%d\n", num);
    num = is_crossed(c, d);
    printf("%d\n", num);
    num = is_crossed(f, z);
    printf("%d\n", num);

    return 0;
}