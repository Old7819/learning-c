#include <stdio.h>

int rusDel(int a, int b)
{
    int mult;   // множитель
    int rem;    // слагаемое
    int part, new_part;

    if (a == b) {
        printf("1\n");
        return 1;
    }

    if (a % 2 == 0) {
        mult = 2;
        rem = 0;
        int n = a/2;
        printf("%d %d %d\n", n, mult, rem);
        part = rusDel(a/2, b);
        new_part = part * mult + rem;
        printf("%d * %d + %d = %d\n", part, mult, rem, new_part);
        return new_part;
    } else {
        mult = 1;
        rem = 1;
        int n = a-b;
        printf("%d %d %d\n", n, mult, rem);
        part = rusDel(a-b, b);
        new_part = part * mult + rem;
        printf("%d * %d + %d = %d\n", part, mult, rem, new_part);
        return new_part;
    }
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", rusDel(a, b));
    return 0;
}