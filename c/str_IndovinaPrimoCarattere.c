#include<stdio.h>
#include<string.h>

void main(){

	char parola1[100];
	fgets(parola1,100,stdin);
	char car='e';
	if (parola1[0] == car) printf("%s inizia con %c",parola1, car);
	else printf("Ritenta");

}
