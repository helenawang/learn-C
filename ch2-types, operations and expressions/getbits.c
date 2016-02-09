#include <stdio.h>

/*getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n){
	return (x>>(p+1-n))&~(~0<<n); //先将x右移使最末一个字符右对齐，再与上“末n位掩码”"
}

int main()
{
	unsigned x=10;
	printf("%d\n",getbits(x,1,2));
	return 0;
}
