#include <stdio.h>

int main()
{
    int n, k;

    scanf("%d", &n);
    
    switch (n % 4) {
        case 1 :
            k = -1;
            break;
        case 2 :
            k = 1;
            break;
        case 3 :
            k = 2;
            break;
        case 0 :
            k = 3;
            break;
    }

    printf("%d\n", k);

    return 0;

}