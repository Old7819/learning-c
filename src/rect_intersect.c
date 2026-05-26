#include <stdio.h>
#define min(a, b)   ((a)<(b) ? (a) : (b))
#define max(a, b)   ((a)>(b) ? (a) : (b))

struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

void printRect(struct Rect *r) 
{
    printf("Прямоугольник: (%d,%d) (%d,%d)\n", r->lt.x, r->lt.y, r->rb.x, r->rb.y);
}

// проверяем, пересекаются ли прямоугольники
int is_crossed(struct Rect a, struct Rect b)
{
    if (a.lt.y < b.rb.y ||    // a ниже b
        b.lt.y < a.rb.y ||    // b ниже a
        a.lt.x > b.rb.x ||    // a правее b
        b.lt.x > a.rb.x)      // b правее a
        return 0;
    return 1;
}

// находим координаты нового прямоугольника при пересечении 
// двух других пряугольников
struct Rect intersection(struct Rect a, struct Rect b) 
{
    struct Rect res;
    res.lt.x = max(a.lt.x, b.lt.x);
    res.rb.x = min(a.rb.x, b.rb.x);
    res.lt.y = min(a.lt.y, b.lt.y);
    res.rb.y = max(a.rb.y, b.rb.y);

    return res;
}

int main()
{   
    struct Rect a = {{-7, 8}, {12, 5}};
    struct Rect b = {{1, 9}, {14, 3}};
    struct Rect res;
    printRect(&a);
    printRect(&b);
    if (is_crossed(a, b))
        res = intersection(a, b);

    printRect(&res);

    return 0;
}