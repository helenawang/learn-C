#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15
#define MAXCHAR 128 //ASCII from 0 to 127 characters are acceptable

/*print horizontal histogram freq. of different characters*/

int main()
{
	int c, i;
	int len; //length of each bar;
	int maxvalue; //maxvalue of all cc[]
	int cc[MAXCHAR]; //bucket
	
	for(i=0; i<MAXCHAR; i++) cc[i] = 0;

	//扫描统计
	while((c=getchar())!='\n'){
		if(c < MAXCHAR) cc[c]++;
	}
	
	//找出最大数量
	maxvalue = 0;
	for(i=1; i<MAXCHAR; i++){
		if(maxvalue < cc[i])
			maxvalue = cc[i];
	}
	
	for(i=1; i<MAXCHAR; i++){
		if(cc[i]>0){
			if((len=cc[i]*MAXHIST/maxvalue)<=0)//由统计值的相对值得出bar的绝对高度
				len = 1;//过少时统一显示为1 
			if(isprint(i))
				printf("%5d - %c - %5d : ",i,i,cc[i]);
			else
				printf("%5d -    - %5d : ",i,cc[i]);
			//打印水平直方图
			while(len-- > 0) putchar('*');
			putchar('\n');
		}
	}
	return 0;
}
