/*Даны через пробел цифра d и целое число в десятичной записи k. 0 <= k <= 2^32
Напечатайте d, k и сколько раз цифра d входит в десятичную запись числа k?*/
#include <stdio.h>

int main()
{
    int d;
    unsigned long long int k;
    int total;
    unsigned long long int temp;

    scanf("%d%llu", &d, &k);
    temp = k;
    total = 0;

    while (temp > 0) {
        int ost = temp % 10;
        if (ost == d) {
            total += 1;
        }
        temp /= 10;
    }
    printf("%d %llu %d\n", d, k, total);

    return 0;
}