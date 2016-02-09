#include <stdio.h>

/*squeeze: delete each char in s1 which appears in s2*/
void squeeze(char s1[], char s2[]){
	int i, j, k;
	for(i=k=0; s1[i]!='\0'; i++){
		for(j=0; s2[j]!='\0' && s2[j]!=s1[i]; j++)
			;
		if(s2[j]=='\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

int main()
{
	char s1[10]="abcde";
	char s2[10]="ace";
	squeeze(s1,s2);
	printf("%s\n",s1);
	return 0;
}
