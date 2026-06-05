/*Некоторые скобочные структуры правильные, другие — неправильные. 
Ваша задача — определить правильная ли скобочная структура*/
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ')' && a == 0) {
            b++;
            break;
        } else if (c == '(') {
            a++;
        } else if (c == ')' && a != 0) {
            a--;
        }
    }

    if ( a == 0 && b == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    return 0;
}