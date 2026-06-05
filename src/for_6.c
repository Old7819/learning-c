#include <stdio.h>

int main()
{
    int d;
    int c;
    int count = 0;

    scanf("%d", &d);

    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            if (c - '0' == d) {
                count++;
            }
        }
    }

    printf("%d ", d);
    putchar(c);
    printf(" %d\n", count);

    return 0;
}