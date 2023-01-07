/* scrivere una funzione f che dato come parametro un numero reale x restituisce
come risultato un valore reale f(x), in cui f è un'espressione nella x a vostro
piacimento. Scrivere una funzione che dati come parametri a,b,n calcola in modo approssimato l'integrale della funzione f nell'intervallo [a,b] usando il metodo dei trapezi: l'integrale si approssima come somma delle aree di n trapezi.
Si suddivide [a,b] in n intervallini di uguale ampiezza e le lunghezze delle
basi sono i valori di f negli estremi degli intervallini.
Scrivere il main che legge i dati del problema, chiama la funzione e scrive
sullo schermo il risultato. */

#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
	return cos(x);
}

double integrale(double a, double b, int n){
	double s = (b-a)/n;
	double ris = 0;
	for(int i=0; i<n; i++)
		ris += ( f(a+i*s) + f(a+(i+1)*s) ) * s / 2;
	return ris;
}
	

int main(){
	double a, b;
	int n;
	cout << "inserisci a, b e n ";
	cin >> a, b, n;

	cout << "l'integrale è " << integrale(a, b, n) << endl;
}