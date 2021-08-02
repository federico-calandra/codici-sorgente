#include<stdio.h>

void main(){

	char frase[100];
	printf("Scrivi una frase:\n");
	fgets(frase,100,stdin);
	int i;
	for(i=0; frase[i]!='\0'; i++){
		if (frase[i] == ' '){
			frase[i] = '-';
		}
	}
	printf("%s",frase);
}
