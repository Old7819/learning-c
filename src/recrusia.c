#include <stdio.h>

long long int ipow(long long int a, unsigned int n, unsigned int * depth);

long long int ipow_rec(long long int a, unsigned int n, unsigned int * depth);

int main()
{
    long long int res;
    unsigned int d = 666;
    res = ipow(2, 32, &d);  // res = 4294967296, d = 6
    printf("Результат: %lld %u\n", res, d);
    res = ipow(3, 12, &d);  // res = 531441, d = 5
    printf("Результат: %lld %u\n", res, d);
    return 0;
}

long long int ipow_rec(long long int a, unsigned int n, unsigned int * depth)
{
    (*depth)++;
    if (n == 0)
        return 1;
    if (n == 1)
        return a;

    if (n % 2 == 0) {
        long long int halt = ipow_rec(a, n / 2, depth); // четное
        return halt * halt;
    } else {
        return a * ipow_rec(a, n-1, depth); // нечетное
    }
}

long long int ipow(long long int a, unsigned int n, unsigned int * depth)
{   
   *depth = 0;  // Сброс счетчика
   return ipow_rec(a, n, depth);
}