#include<stdio.h>

void main(){

	char frase[100];
	printf("Scrivi una frase:\n");
	fgets(frase,100,stdin);
	int i;
	int numSpazi = 0;
	for(i=0; frase[i]!='\0'; i++)	// gli apici singoli per i caratteri
		{if(frase[i] == ' ') numSpazi++;}
	printf("Ci sono %d spazi",numSpazi);

}
