#include <stdio.h>
/*Дано натуральное число n, потом n целых чисел.
Вычислить и напечатать самое маленькое из них.
Напечатать сначала числа через пробел. На следующей строке напечатать минимальное число.*/
int main()
{
    int n;
    int i;
    int min;
    int m;
    int temp;

    printf("Введите количество чисел\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        //printf("Введите число\n");
        scanf("%d", &m);
        printf("%d ", m);
        min = m;
        temp = m;
        //printf("temp=%d m=%d\n", temp, m);
        if (temp > m) {
            min = m;
        } else {
            temp = m;
        }
        //printf("temp=%d m=%d\n", temp, m);
    }
    printf("\n%d\n", min);
    
    return 0;
}