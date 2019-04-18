#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int number = rand(), a, b = 0;
    number = number % 100 + 1;

    while (a != number) {
	scanf("%d", &a);
	b++;

	if (a > number) {
	    printf("大\n");
	} else if (a < number) {
	    printf("小\n");
	} else {
	    printf("对，%d次\n", b);
	    return 0;
	}

	a = 0;
    }
}
