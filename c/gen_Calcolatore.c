/* Scrivere un programma che legga da tastiera due numeri a e b (anche conv irgola) e un operatore tra + - / % e stampi il risultato ottenuto applicando l’operatore ai due numeri inseriti. Per l’operazione % gli operandi sono bac e bbc */

#include<stdio.h>
#include<math.h>

void main(){
	float a,b;
	char op;
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%c",&op);
	 
	switch (op){
		case "+": printf("%f",a+b); break;
		case "-": printf("%f",a-b);break;
		case "*": printf("%f",a*b);break;
		case "/": printf("%f",a/b);break;
		default: printf("opzione non valida");
	}
}
