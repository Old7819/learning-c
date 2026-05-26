#include <stdio.h>

int rusMult(int a, int b);

int main()
{
    int a = 100;
    int b = 37;
    printf("%d\n", rusMult(a, b));
    return 0;
}

int rusMult(int a, int b)
{
    int res, ost, new_res;

    if (b == 0) {
        return 0;
    }
    
    // Базовый случай: последний вызов
    if (b == 1) {
        printf("%d %d\n", a, b);  // Рекурсивный спуск
        printf("%d\n", a);         // Последнее значение a
        return a;
    }

    // Рекурсивный спуск: печать a и b
    printf("%d %d\n", a, b);

    if (b % 2 == 1) {
        res = rusMult(a * 2, b / 2);
        ost = b % 2;
        new_res = a + res;
        printf("%d %d %d %d\n", res, a, ost, new_res);
        return new_res;
    } else {
        res = rusMult(a * 2, b / 2);
        ost = b % 2;
        new_res = res;
        printf("%d %d %d %d\n", res, a, ost, new_res);
        return new_res;
    }
}