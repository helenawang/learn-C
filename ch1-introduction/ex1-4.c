#include <stdio.h>
int main()
{
	float fahr, celsius, step;
	float lower, upper;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Celsius  Fahr\n");
	celsius = lower;
	while(celsius <= upper){
		fahr = (9.0 * celsius)/5.0 + 32.0;
		printf("%6.0f   %4.1f\n",celsius,fahr);
		celsius += step;
	}
	return 0;
}
