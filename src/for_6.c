#include <stdio.h>
/*Сколько раз встретилась цифра в ОЧЕНЬ БОЛЬШОМ числе?*/

int main()
{
    int d;
    int c;
    int count = 0;

    scanf("%d", &d);
    printf("%d ", d);

    getchar();

    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            putchar(c);
            if (c - '0' == d) {
                count++;
            }
        }
    }

    printf(" %d\n", count);

    return 0;
}