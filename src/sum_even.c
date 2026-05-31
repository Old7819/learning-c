#include <stdio.h>
/*Дано натуральное число n, потом n целых чисел.
Вычислить и напечатать сумму только четных чисел.*/
int main()
{
    int n;
    int sum;
    int i;
    int m;

    printf("Введите количество чисел\n");
    scanf("%d", &n);

    sum = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        if (m % 2 == 0) {
            sum += m;
        }
    }
    printf("%d\n", sum);

    return 0;
}