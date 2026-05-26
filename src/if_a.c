#include <stdio.h>

int num(int a)
{
    return (a % 3 == 0 || a % 5 == 0) && a % 15 != 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%s\n", num(n) ? "YES" : "NO");
    
    return 0;
}