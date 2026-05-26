#include <stdio.h>

int main()
{
    char x, xt, xr, xn, xl;
    int y, yt, yr, yn, yl;
    scanf("%c%d", &x, &y);
    xt = x - 1;
    yt = y;
    xr = x;
    yr = y + 1;
    xn = x + 1;
    yn = y;
    xl = x;
    yl = y - 1;
    printf("%c%d %c%d %c%d %c%d\n", xt, yt, xr, yr, xn, yn, xl, yl);

    return 0;

}