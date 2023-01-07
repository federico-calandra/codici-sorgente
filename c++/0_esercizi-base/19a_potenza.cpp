/* legge un numero reale x e un numero intero n e che calcola x alla n senza usare pow.
Gestire anche il caso in cui n è minore o uguale a zero. */

#include <iostream>

using namespace std;

int main()
{
	double x, ris;
	int n;

	cout << "inserisci base ";
	cin >> x;

	cout << "inserisci esponente ";
	cin >> n;

	if(n > 0)
	{
		ris = 1;
		for(int i = 1; i <= n; i++)
			ris *= x;
		cout << ris << endl;
	}

	else if(n < 0)
	{
		ris = 1;
		for(int i = 1; i <= -n; i++)
			ris *= x;
		ris = 1/ris;
		cout << ris << endl;
	}

	else if(n == 0)
	{
		if(x != 0)
		{
			ris = 1;
			cout << ris << endl;
		}
		else
			cout << "non valido" << endl;
	}
}
