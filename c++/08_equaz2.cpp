// chiede i coefficienti di ax²+bx+c=0 e restituisce le soluzioni reali, se esistono

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// chiedo i coefficienti e calcolo il discriminante
	double a, b, c;
	cout << "inserisci i coefficienti a, b, c dell'equazione ax²+bx+c=0\n";
	cin >> a >> b >> c;
	double delta = pow(b,2) - 4*a*c;

	double x1, x2;

	// verifico se ha soluzioni reali
	if(delta < 0)
		cout << "non esistono soluzioni reali";

	// due soluzioni reali e coincidenti
	else if(delta == 0)
		{
			x1 = -b/(2*a);
			x2 = x1;
			cout << "la soluzione è " << x1 << endl;
		}
	// due soluzioni reali e distinte
		else
		{
			x1 = (-b + sqrt(delta))/(2*a);
			x2 = (-b - sqrt(delta))/(2*a);
			cout << "le soluzioni sono " << x1 << " e " << x2 << endl;
		}
}


