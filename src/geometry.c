#include <stdio.h>

void centr(int x1, int y1, int x2, int y2, int * xc, int * yc) {
    int w = (x2 - x1) / 2; 
    int h = (y1 - y2) / 2; 
    *xc = x1 + w;
    *yc = y1 - h;
}   

void move(int * px, int * py, int dx, int dy) {
    *px += dx;
    *py += dy;
}
void move2(int * x1, int * y1, int * x2, int * y2, int dx, int dy) {
    move(x1, y1, dx, dy);
    move(x2, y2, dx, dy);
}

void rotate0(int * x1, int * y1, int * x2, int * y2) {
    int w = (*x2 - *x1) / 2; 
    int h = (*y1 - *y2) / 2; 

    *x1 = -h;
    *x2 = h;    
    *y1 = w;
    *y2 = -w;
}

void rotateC(int * x1, int * y1, int * x2, int * y2) {
    int xc, yc;
    centr(*x1, *y1, *x2, *y2, &xc, &yc);
    printf("xc=%d yc=%d\n", xc, yc);
    move2(x1, y1, x2, y2, -xc, -yc);
    printf("%d %d %d %d\n", *x1, *y1, *x2, *y2);
    rotate0(x1, y1, x2, y2);
    printf("%d %d %d %d\n", *x1, *y1, *x2, *y2);
    move2(x1, y1, x2, y2, xc, yc);
    printf("%d %d %d %d\n", *x1, *y1, *x2, *y2);
}

int main() {
    int x1, y1, x2, y2;
    
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    
    rotateC(&x1, &y1, &x2, &y2);
    printf("%d %d %d %d\n", x1, y1, x2, y2);
    
    return 0;
}