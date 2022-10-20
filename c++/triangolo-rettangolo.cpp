// legge da tastiera i cateti di un triangolo rettangolo, stampa area e perimetro

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double c1, c2;
	double a, p;
	
	cout << "inserisci cateti\n";
	cin >> c1 >> c2;
	
	a = c1 * c2 / 2;
	p = c1 + c2 + sqrt(pow(c1,2) + pow(c2,2));
		
	cout << "l'area è " << a << endl;
	cout << "il perimetro è " << p;
}
