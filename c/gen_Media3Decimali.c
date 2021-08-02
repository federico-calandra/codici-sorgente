/* Scrivere un programma che legga da tastiera tre numeri (anche con virgola)e stampi in uscita la media, riportandola con tre cifre decimali. */

#include<stdio.h>

float main() {
	float x,y,z,m;
	scanf("%f", &x);
	scanf("%f", &y);
	scanf("%f", &z);
	m = (x+y+z)/3;
	printf("%0.3f", m);
}
