#include <stdio.h>

int main() {
    double a, b;

    printf("输入要相加的数:\n");
    scanf("%lf %lf", &a, &b);
    printf("%f+%f=%f\n", a, b, a + b);

    return 0;
}
