#include <stdio.h>


#define GALEON 17   // 1 galleon = 17 sickles
#define SICKLE 29   // 1 sickle = 29 knuts

int money2knats(int g, int s, int k)
{
    return ((g*GALEON) + s) * SICKLE + k;
}


void knats2money(int t, int *pg, int *ps, int *pk)
{
    int g, s, k;    // создадим локальные переменные

    k = t % SICKLE;    // осталось кнатов
    s = t / SICKLE;    // сиклей большой кучей
    g = s / GALEON;
    s = s % GALEON;

    // по указателям изменим значения переменных
    *pk = k;
    *ps = s;
    *pg = g;
}


int main()
{
    int g1, s1, k1, t1;     // кошелек1
    int g2, s2, k2, t2;     // кошелек2
    int g, s, k, t;        // кошелек результат


    scanf("%d%d%d", &g1, &s1, &k1);
    scanf("%d%d%d", &g2, &s2, &k2);


    // из монет - в общее количество кнатов
    t1 = money2knats(g1, s1, k1);      // кошелек1
    t2 = money2knats(g2, s2, k2);      // кошелек2


    // кошелек = кошелек1 + кошелек2
    t = t1 + t2;


    // из общего количества кнатов - обратно в монеты
    knats2money(t, &g, &s, &k);


    // печатаем результат
    printf("%d %d %d\n", g, s, k);


    return 0;
}