#include <stdio.h>

/* Функция печати одного сомножителя */
void printFactor(unsigned int last, unsigned int n) {
    if (n == 0) return;          // Если степень 0, ничего не печатаем
    if (n == 1)
        printf("%u ", last);     // Степень 1 не указываем
    else
        printf("%u^%u ", last, n);
}

/* Рекурсивная функция разложения */
void simpleFactors(unsigned int a, unsigned int last, unsigned int n) {
    if (a == 1) {
        printFactor(last, n);    // Печатаем последний найденный множитель
        return;
    }

    if (a % last == 0) {
        // Делится без остатка → увеличиваем степень, продолжаем с тем же last
        simpleFactors(a / last, last, n + 1);
    } else {
        // Не делится → сначала уходим в рекурсию для БОЛЬШИХ делителей
        simpleFactors(a, last + 1, 0);
        // Печатаем ТЕКУЩИЙ множитель при возврате (это даст порядок от большего к меньшему)
        printFactor(last, n);
    }
}

/* Точка входа */
int main() {
    unsigned int a;
    
    // Читаем число с клавиатуры
    if (scanf("%u", &a) == 1) {
        // last = 2 (начинаем проверку с двойки)
        // n = 0 (степень пока не считали)
        simpleFactors(a, 2, 0);
        printf("\n"); // Перевод строки в конце вывода
    }
    
    return 0;
}