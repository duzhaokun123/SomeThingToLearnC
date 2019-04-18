#include <stdio.h>

int main ()
{
	int s,m,h;
	int sl,ml;
	const int x = 60;

	printf ("输入秒\n");
	scanf ("%d",&s);

	m = s / x;
	sl = s % x;
	h = m / x;
	ml = m % x;

	printf ("%d秒是%d时%d分%d秒\n",s,h,ml,sl);
	return 0;
}
