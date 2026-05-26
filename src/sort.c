#include <stdio.h>

void sort2(int * a, int * b) {
    if (*a > *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
}

void sort3(int * x, int * y, int * z) {
    sort2(x, y);
    sort2(y, z);
    sort2(x, y);
}

int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    sort3(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    return 0;
}