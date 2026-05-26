#include <stdio.h>

int main()
{
    int L;  // сколько отряд прошел в первый день
    int k;  // на сколько больше пройдет завтра
    int s;  // сколько нужно всего пройти

    int i;		// закончилось дней
	int step;	// проходим за 1 день
	int path;	// прошли всего с начала похода

    scanf("%d", &L);
    scanf("%d", &k);
    scanf("%d", &s);

    i = 0;
    step = L;
    path = 0;

    while (path < s) {
        path += step;
        i++;
        step += k;
    }

    printf("%d\n", i);

    return 0;
}