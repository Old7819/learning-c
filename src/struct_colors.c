#include <stdio.h>

typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

// считать RGB-формат с консоли
Color getColor();
// перевод из RGB-формата в число
unsigned long long convertToHTML(Color);
// преобразование числа цвета в RGB-формат
Color convertToRGB(unsigned long long);
// печать цвета в RGB-формате (печать значений в десятичном виде через пробел)
// red green blue:
// 255 128 222
// Печатать только числа через пробел и \n в конце!!!
void printRGB(Color);

// печать цвета в HTML-формате и \n в конце.
// Примеры: FFA902 0AA3FF
void printHTML(Color);

int main(){
    Color z, z2;
    unsigned long long html;

    z = getColor();
    printRGB(z);

    html = convertToHTML(z);
    printf("%llu\n", html);
    printHTML(z);

    z2 = convertToRGB(html);
    printRGB(z2);

    return 0;
}

Color getColor()
{
    Color a;
    scanf("%hhu%hhu%hhu", &a.red, &a.green, &a.blue);
    return a;
}

unsigned long long convertToHTML(Color n)
{
    return n.red*65536 + n.green*256 + n.blue;
}

Color convertToRGB(unsigned long long r)
{
    Color rgb;
    rgb.blue = r % 256;
    rgb.green = (r / 256) % 256;
    rgb.red = (r / 65536) % 256;
    return rgb;
}

void printRGB(Color a)
{
    printf("%hhu %hhu %hhu\n", a.red, a.green, a.blue);
}

void printHTML(Color b)
{
    printf("%02X%02X%02X\n", b.red, b.green, b.blue);
}