#include <stdio.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	if(argc==1)
	{
		printf("Error! No input image.\n");
		return 1;
	}
	else
		while(--argc>0)
		{
			if((fp=fopen(*++argv,"wb"))==NULL)
			{
				printf("cat: can't open &s\n",*argv);
				return 1;
			}else
			{
				int startingLBA=0x0000003f;
				fwrite(&startingLBA,sizeof(int),1,fp);
				fclose(fp);
			}
		}
	return 0;
}