/* Definire una struct per rappresentare i dati di un elemento chimico, con nome, massa atomica (A) e numero atomico (Z).
Scrivere una funzione che legge da tastiera nome, massa e numero atomico, crea l’elemento con new e restituisce come risultato l’indirizzo.
Scrivere una funzione che visualizza i dati di un elemento avendo come parametro il puntatore.
Scrivere il main, che nell’ordine chiama la prima funzione (e quindi si memorizza l’indirizzo dell’elemento), chiama la seconda funzione e infine elimina l’elemento con delete. */

#include <iostream>
//#include <cmath>
//#include <vector>

using namespace std;

//int constexpr N = 0;

crea_atomo(){
	string n;
	double m;
	int z;
	cin>>n>>m>>z;
	new atomo;
}

int main(){

	struct atomo{
		string nome;
		double massa;
		int z;
	};

}
