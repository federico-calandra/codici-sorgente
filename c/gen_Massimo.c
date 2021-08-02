/* Scrivere un programma che legga da tastiera tre numeri interi e stampi ilmassimo tra i tre */

#include<stdio.h>

void main(){
	int x,y,z,max;
	scanf("%i",&x);
	scanf("%i",&y);
	scanf("%i",&z);
	
	max = x;
	if (y > max) max = y;
	if (z > max) max = z;
	
	printf("%i", max);
}
