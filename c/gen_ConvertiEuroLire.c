#include<stdio.h>

void main(){

	long euro, lire, k = 1927;
	printf("inserisci euro: ");
	scanf("%ld",euro);
	lire=k*euro;
	printf("%ld euro sono %ld lire",euro,lire);
}
