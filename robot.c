#include <stdio.h>

int next_step(int step, int k)
{
    step -= k;
    if (step < 0)
        step = 0;
    return step;
}

int main()
{
    int s, L, k;
    scanf("%d%d%d", &s, &L, &k);
    int step = L;
    int i = 0;
    int dist = s;
    int path = 0;

    while (step <= dist && step != 0) {
        path += step;
        dist -= step;
        i++;
        printf("За %d шаг прошел %d см, всего %d, осталось %d\n", i, step, path, dist);
        step = next_step(step, k);
    }
    
    printf("%d %d\n", i, dist);

    return 0;
}