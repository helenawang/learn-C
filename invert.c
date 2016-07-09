#include <stdio.h>

/* invert: inverts the n bits of x that begins at position p(right adjusted)*/
unsigned invert(unsigned x, int p, int n){
	return x^(~(~0<<n)<<(p+1-n));
}

int main()
{
	unsigned x=6;
	printf("%d\n",invert(x,2,2));
	return 0;
}
