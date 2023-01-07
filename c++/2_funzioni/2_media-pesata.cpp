/* definire una funzione che dati come parametri due array x e w di numeri reali
e la loro dimensione n (si supponga che i due array abbiano la stessa dimensione)
restituisce come risultato la media pesata degli elementi di x pesati con i valori 
di w. */

#include <iostream>
#include <cmath>

using namespace std;
int constexpr N=5;

int mediaPesata(double x[], double w[])
{
	double m = 0;
	for(int i=0; i<N; i++)
		m += w[i] * x[i];
	m /= N;
	return m;
}

int main(){
	double x[N];
	for(int i=0; i<N; i++){
		cout << "inserisci valore ";
		cin >> x[i];}

	double w[N];
	for(int i=0; i<N; i++){
		cout << "inserisci peso ";
		cin >> w[i];}

	cout << "la media pesata è " << mediaPesata(x, w) << endl;
}