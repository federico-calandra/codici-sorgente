/* Scrivere un programma che legga da tastiera un numero interoxe stabiliscail numero di byte necessario a memorizzarexvariabili di tipo intero. */

#include<stdio.h>

int main() {
	int x, m;
	scanf("%d", &x);
	printf("%d\n",x * (int) sizeof(int));
}
