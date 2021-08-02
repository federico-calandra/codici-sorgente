#include<stdio.h>

void main(){
	int len=100;
	char frase[len];	// l'array è lungo 100
	printf("Scrivi qualcosa\n");
	fgets(frase, len/2, stdin);	// leggo 50 caratteri
	printf("Quello che hai scritto è:\n%s",frase);
}
