// legge il raggio di una circonferenza, stampa area e circonferenza

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double r;
	double a, c;
	
	cout << "inserisci raggio ";
	cin >> r;
	
	a = M_PI * pow(r,2);
	c = 2 * M_PI * r;
	
	cout << "l'area è " << a << endl;
	cout << "la circonferenza è " << c;
}
