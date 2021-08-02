#include<stdio.h>
#include<string.h>

void main(){

	char str[100];
	char strinv[100];
	printf("Scrivi una parola:\n");
	fgets(str,100,stdin); 
	int i;
	for(i=0; str[i]!='\0'; i++)		strinv[i] = str[strlen(str)-1-i];
	if(strcmp(str,strinv)==0)		printf("è palindroma");
	printf("%s%s", str,strinv);

	// si comporta in modo strano per |str|>6
}
