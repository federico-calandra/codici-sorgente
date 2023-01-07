/* scrivere un programma che usa la funzione dell'esercizio 41a) e
conta quanti sono i numeri primi in un intervallo di numeri interi [n1,n2],
ove n1 e n2 sono inseriti dall'utente
Volendo, definire una funzione che svolge il conteggio dati n1 e n2. */

#include <iostream>
#include <cmath>

using namespace std;

bool primo(int n){
	int d = 2;
	bool primo = true;

	while(primo==true && d<n){
		if(n%d == 0){
			primo = false;
			break;}
		else
			d++;
	}
	
	return primo;
	
}
	

int main(){
	int n1, n2;
	cout << "inserisci n1 e n2 ";
	cin >> n1 >> n2;

	int ris = 0;

	for(int n=n1; n<=n2; n++)
		if(primo(n)==true)
			ris++;

	cout << ris << endl;
}