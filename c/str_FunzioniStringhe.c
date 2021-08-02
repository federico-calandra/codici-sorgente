#include<stdio.h>
#include<string.h>

void main(){

	char frase1[100];
	char frase2[100];
	strcat(frase1,frase2);	// il risultato viene sovrascritto su frase1
	printf("Scrivi una frase:\n");
	fgets(frase1,100,stdin);
	printf("Scrivi un'altra frase:\n");
	fgets(frase2,100,stdin);

	// Concatenazione
	printf("La concatenazione contiene %ld caratteri", strlen(frase1));

	// Confronto alfabetico
	int cfr;
	cfr = strcmp(frase1,frase2);
	if (cfr == 0) {printf("Le stringhe sono uguali");}
	if (cfr >0) {"%s viene prima di %s", frase1, frase2);

}
