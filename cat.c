#include <stdio.h>
/*cat: concatenate files, ver1 */
int main(int argc, char const *argv[])
{
	FILE *fp;
	void filecopy(FILE *ifp,FILE *ofp);
	if(argc==1)
		filecopy(stdin,stdout);
	else
		while(--argc>0)
		{
			if((fp=fopen(*++argv,"r"))==NULL)
			{
				printf("cat: can't open &s\n",*argv);
				return 1;
			}else
			{
				filecopy(fp,stdout);
				fclose(fp);
			}
		}
	return 0;
}
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;
	while((fscanf(ifp,"%c",&c)!=EOF))
		printf("%c", c);
	return ;
}