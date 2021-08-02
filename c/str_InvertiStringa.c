#include<stdio.h>
#include<string.h>

void main(){

	char str[100];
	char strinv[100];
	printf("Scrivi una parola:\n");
	fgets(str,100,stdin); 
	int i;
	for(i=0; str[i]!='\0'; i++){
		strinv[i] = str[strlen(str)-1-i];}
	printf("%s",strinv);

}
