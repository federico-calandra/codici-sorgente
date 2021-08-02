/* Scrivere un programma che legga da tastiera un numero che rappresenta unnumero di secondi, e stampi le ore, i minuti e i secondi compresi. */
#include<stdio.h>

void main(){
	int time,h,m,s;
	scanf("%i",&time);
	if (time < 60)	printf("0 h  0 min  %i s",time);
	if (time > 60 && time < 3600) {
		m = time / 60;
		s = time % 60;
		printf("0 h  %i min  %i s",m,s);
	}
	if (time > 3600) {
		h = time / 3600;
		m = (time - 3600) / 60;
		s = (time - 3600) % 60;
		printf("%i h  %i min  %i s",h,m,s);
	}
}
