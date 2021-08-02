/* Scrivere un programma che legga da tastiera un numero e stabilisca se pari o meno, stampando in uscita rispettivamente 1 o 0. */
#include<stdio.h>

void main(){
	int x;
	scanf("%i",&x);
	if (x % 2 == 0) printf("1");	/* numero pari */
	if (x % 2 == 1) printf("0");
}
