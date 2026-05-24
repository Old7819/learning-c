#include <stdio.h>

int main()
{
    char m = 10;    // месяц
    char day = 5;   // день
    char d;         // день от начала сезона
    char season;    // сезон

    // Сезоны: зима - 0, весна - 1, лето - 2, осень - 3
    switch (m) {
        case 12 :
            d = day;
            season = 0;
            break;
        case 1 :
            d = (31 + day);
            season = 0;
            break;
        case 2 :
            d = (31 + 31 + day);
            season = 0;
            break;
        case 3 :
            d = day;
            season = 1;
            break;
        case 4 :
            d = (31 + day);
            season = 1;
            break;
        case 5 :
            d = (31 + 30 + day);
            season = 1;
            break;
        case 6 :
            d = day;
            season = 2;
            break;
        case 7 :
            d = (30 + day);
            season = 2;
            break;
        case 8 :
            d = (30 + 31 + day);
            season = 2;
            break;
        case 9 :
            d = day;
            season = 3;
            break;
        case 10 :
            d = (30 + day);
            season = 3;
            break;
        case 11 :
            d = (30 + 31 + day);
            season = 3;
            break;
    }

    printf("%d %d\n", season, d);
    return 0;
}