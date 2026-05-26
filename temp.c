#include <stdio.h>
#include <assert.h>
#include <math.h>
#define EPS 0.0001

float fhar(int cel) {

    float res;
    res = (cel * 1.8) + 32;
    return res;
}

// сравнивает числа a и b с точностью EPS
int eps(float a, float b) {

    return fabs(33.8 - fhar(1)) < EPS;
}

int main() {

    int cel; // градусы цельсия
    float f; // градусы фаренгейта

    // тесты
    assert(32 == fhar(0));
    assert(eps(33.8, fhar(1)));
    assert(122 == fhar(50));
    assert(-40 == fhar(-40));

    // для произвольного числа
    scanf("%d", &cel);
    f = fhar(cel);
    printf("C = %d F = %.2f\n", cel, f);


    return 0;
}