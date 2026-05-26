#include <stdio.h>

int main()
{
    float x, y;
    scanf("%f%f", &x, &y);

    if ((-3 <= x && 2 >= x) && (-4 <= y && 6 >= y))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}