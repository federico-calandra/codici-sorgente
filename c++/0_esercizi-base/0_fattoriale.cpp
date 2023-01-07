// stampa il fattoriale di un numero

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "inserisci numero ";
	int n;
	cin >> n;

	int fatt = 1;
	for(int i = 1; i <= n; i++)
		fatt *= i;

	cout << "il fattoriale di n è " << fatt;
}
