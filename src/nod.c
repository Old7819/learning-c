#include <stdio.h>

int nod(int a, int b)
{
    // базовый случай: если второе число 0, НОД = первое число
    if (b == 0) {
        return a;
    }
    // рекурсивный случай: заменяем (a, b) на (b, a %b)
    else {
        return nod(b, a % b);
    }
}

int main()
{
    int a = 44, b = 256;
    printf("НОД(%d, %d) = %d\n", a, b, nod(a, b));

    return 0;
}