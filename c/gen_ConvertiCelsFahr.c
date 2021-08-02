/* Scrivere un programma che legga da tastiera un valore di temperatura (anche decimale) espresso in gradi Celsius e ne stampi la conversione in gradi Fahrenheit usando due cifre decimali. (F=C×1.8 + 32) */

#include<stdio.h>

float main() {
	float c,f;
	scanf("%f",&c);
	f = 1.8*c + 32;
	printf("%f",f);
}
