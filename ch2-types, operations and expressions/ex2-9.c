#include <stdio.h>

/* bitcount: count 1 bits in a faster version*/
int bitcount(unsigned x){
	int b;
	for(b=0; x!=0; x &= x-1)//每次清除最右边的1
		b++;
	return b;
}

int main()
{
	int x=11;
	printf("%d\n",bitcount(x));
	return 0;
}
