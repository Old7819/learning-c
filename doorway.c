#include <stdio.h>

void sort2(int * a, int * b) {
    if (*a > *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
}

void sort3(int * a, int * b, int * c) {
    sort2(a, b);
    sort2(b, c);
    sort2(a, b);
}

int main()
{
    int w, h;   // проем двери
    int a, b, c;    // размер холодильника
    scanf("%d%d", &w, &h);
    scanf("%d%d%d", &a, &b, &c);
    sort2(&w, &h);
    sort3(&a, &b, &c);
    printf("%s\n", (a <= w && b <= h) ? "YES" : "NO");
    return 0;
}