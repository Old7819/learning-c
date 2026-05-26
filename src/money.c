#include <stdio.h>

int main()
{
    int price = 1;
    int delta = 5;
    int money = 100;
    //scanf("%d%d%d", &price, &delta, &money);
    int wday = 0;   // номер дня недели
    int day = 0;
    while (money >= price) {
        wday++;
        money -= price;
        day++;
        printf("День недели %d\n", wday);
        printf("В %d день потратили %d монет, осталось %d монет\n", day, price, money);
        
        if (wday >= 7) {
            wday = 0;
            price += delta;
        }
    }
    printf("%d\n", day);
    return 0;
}