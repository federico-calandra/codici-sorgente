/* definire una funzione che dati come parametri i tre coefficienti a,b,c di un'equazione di
secondo grado restituisce come risultato il numero di soluzioni distinte (0, 1 o 2). */

#include <iostream>
#include <cmath>

using namespace std;

int numeroSoluzioni(double a, double b, double c)
{
	double delta = b*b - 4*a*c;
	int n;

	if(delta==0)
		n = 1;
	else if(delta>0)
		n = 2;
	else
		n = 0;
	
	return n;
}

int main(){
	cout << "inserisci a, b, e c ";
	double a, b, c;
	cin >> a >> b >> c;
	cout << "l'equazione ha " << numeroSoluzioni(a, b, c) << " soluzioni" << endl;
}