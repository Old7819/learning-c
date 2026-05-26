#include <stdio.h>

typedef struct
{
    int yy; // год
    char mm; // месяц
    char dd; // день
}Data;

typedef struct
{
    int yy; // год
    char season; // время года (зима - 0, весна - 1, лето - 2, осень - 3)
    int day; // день от начала текущего времени года
}Season;


// получает параметры даты с консоли (три целых числа через тире:
// YYYY-MM-DD)
// Например, 2020-12-13
Data getData()
{
    Data d;
    scanf("%d-%hhd-%hhd", &d.yy, &d.mm, &d.dd);
    return d;
}

// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data d)
{
    printf("%04d-%02d-%02d\n", d.yy, d.mm, d.dd);
}

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая, лето - с 1 июня по 31 августа,
// осень - с 1 сентября по 30 ноября
Season convToSeas(Data d)
{
    Season s;
    s.yy = d.yy;    // год не меняется
    
    // определяем сезон
    switch(d.mm) {
        case 12:
            s.season = 0;
            s.day = d.dd;
            break;
        case 1:
            s.season = 0;
            s.day = 31 + d.dd;
            break;
        case 2:
            s.season = 0;
            s.day = 31 + 31 + d.dd;
            break;
        case 3:
            s.season = 1;
            s.day = d.dd;
            break;
        case 4:
            s.season = 1;
            s.day = 31 + d.dd;
            break;
        case 5:
            s.season = 1;
            s.day = 31 + 30 + d.dd;
            break;
        case 6:
            s.season = 2;
            s.day = d.dd;
            break;
        case 7:
            s.season = 2;
            s.day = 30 + d.dd;
            break;
        case 8:
            s.season = 2;
            s.day = 30 + 31 + d.dd;
            break;
        case 9:
            s.season = 3;
            s.day = d.dd;
            break;
        case 10:
            s.season = 3;
            s.day = 30 + d.dd;
            break;
        case 11:
            s.season = 3;
            s.day = 30 + 31 + d.dd;
            break;
        default:
            printf("Wrong test data!\n");
    }
    return s;
}
//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года,
// DD - день от начала времени года, завершая переносом строки
void printSeas(Season d)
{
    printf("%04d-%02d-%02d\n", d.yy, d.season, d.day);
}

int main()
{
    Data dat;
    Season seas;
    dat = getData();
    printData(dat);
    seas = convToSeas(dat);
    printSeas(seas);

    return 0;
}