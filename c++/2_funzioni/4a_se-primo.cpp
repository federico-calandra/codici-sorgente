/* scrivere una funzione che dato come parametro un numero naturale n
restituisce true se n è un numero primo.
Scrivere il main che legge i dati del problema, chiama la funzione e scrive
sullo schermo il risultato. */

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
	int n;
	cout << "inserisci numero ";
	cin >> n;

	cout << primo(n)<< endl;
}