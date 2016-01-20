#include <stdio.h>
main()
{
	int c,bl,ta,nl;
	bl=ta=nl=0;
	while((c=getchar())!=EOF)
	{
		if(c==' ') bl++;
		else if(c=='\t') ta++;
		else if(c=='\n') nl++;
	}
	printf("%d %d %d\n",bl,ta,nl);
}
