#include <stdio.h>
#define MAXHIST	15 /*max length of histogram*/
#define MAXWORD 11 /*max length of a word*/
#define IN  1
#define OUT 0

/*print vertical histogram*/
int main()
{
	int c,i,j,nc,state;
	int maxvalue;	/*max value for wl[]*/
	int ovflow;
	int wl[MAXWORD];/*word length counters*/

	state = OUT;
	nc = 0;			/*number of chars in a word*/
	ovflow = 0;		/*number of words >= MAXWORD*/
	for(i=0; i<MAXWORD; ++i) wl[i]=0;
	while((c=getchar())!=EOF){
		if(c==' ' || c=='\t' || c=='\n'){
			state = OUT;
			if(nc > 0)
				if(nc < MAXWORD) ++wl[nc];
				else ++ovflow;
			nc = 0;
		}else if(state = OUT){
			state = IN;
			nc = 1;
		}else ++nc;
	}
	//record the max length in order to balance the view
	maxvalue=0;
	for(i=1; i<MAXWORD; i++){
		if(maxvalue < wl[i])
			maxvalue = wl[i];
	}
	for(i=MAXHIST; i>0; --i){
		for(j=1; j<MAXWORD; ++j){
			if(wl[j]*MAXHIST/maxvalue >= i)
				printf("  *  ");
			else printf("     ");
		}
		putchar('\n');
	}
	for(i=1; i<MAXWORD; i++)
		printf("%4d ",i);
	putchar('\n');
	for(i=1; i<MAXWORD; i++)
		printf("%4d ", wl[i]);
	putchar('\n');
	if(ovflow>0)
		printf("There are %d words >= %d\n",ovflow,MAXWORD);
	return 0;
}
