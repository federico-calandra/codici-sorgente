#include<stdio.h>
#include<string.h>

void main(){

	char parola1[100];
	char parola2[100];
	fgets(parola1,100,stdin);
	fgets(parola2,100,stdin);
	printf("%d", strcmp(parola1,parola2));
	// come le altri funzioni di stirng.h, la funzione strcmp considera gli args in ordine inverso
	if(strcmp(parola1,parola2)>0)	printf("%s%s",parola2,parola1);
	if(strcmp(parola1,parola2)<0)	printf("%s%s",parola1,parola2);
	else	printf("le parole sono uguali");
	

}
