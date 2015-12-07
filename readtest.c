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
			if((fp=fopen(*++argv,"rb"))==NULL)
			{
				printf("cat: can't open &s\n",*argv);
				return 1;
			}else
			{
				fseek(fp,446+8L,SEEK_SET);
				int startingLBA;
				fread(&startingLBA,sizeof(int),1,fp);
				printf("%d\n", startingLBA);
				fclose(fp);
			}
		}
	return 0;
}