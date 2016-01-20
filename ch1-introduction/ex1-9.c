#include <stdio.h>
main()
{
	int c;
	while((c=getchar())!=EOF)
	{
		if(c!=' ') putchar(c);
		else
		{
			while((c=getchar())!=EOF&&c==' ') ;
			putchar(' ');
			putchar(c);
		}
	}
}
