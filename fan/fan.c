#include <stdio.h>

int main() {
    int a, b, c;
    a = 364;
    while (a != 0) {
        b = a % 10;
        a = a / 10;
        c = c * b;
    }
    printf("%f", b);
    return 0;
}
