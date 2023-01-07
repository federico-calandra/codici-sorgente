/* legge le cifre binarie di un numero naturale
(ad esempio una alla volta e inserite in un vector) e che calcola
il numero e lo visualizza (in base 10).
Ad esempio se le cifre sono 1 1 0 0 1 il risultato è 25. */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n=5;	
	vector<int> bin(n);
	int dec = 0;
	
	for(int i=0; i<n; i++){
		cout << "inserisci elemento ";
		cin >> bin[n-1-i];
	}

	for(int i=0; i<n; i++)
		dec += bin[i] * pow(2,i);
	
	cout << "il numero è " << dec << endl;
}
