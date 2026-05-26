#include <stdio.h>

int triangle_len_type(int a, int b, int c)
{
    if (a >= b + c || b >= a + c || c >= a + b)
        return -1;
    if (a == b && b == c)
        return 2;
    if (a == b || b == c || a == c)
        return 1;
    return 0;
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int res = triangle_len_type(a, b, c);
    printf("%d\n", res);
    return 0;
}