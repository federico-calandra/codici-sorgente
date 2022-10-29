// stampa il coefficiente binomiale "n su k" con k <= n

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "inserisci n ";
	int n;
	cin >> n;
	
	cout << "inserisci k ";
	int k;
	cin >> k;
	
	if(k > n)
		cout << "k non può essere > di n";
	// se k>n il programma dovrebbe interrompersi, invece così va avanti lo stesso

	int num = 1, denom = 1;
	
	for(int i = n-k+1; i <= n; i++)
		num *= i;
		
	for(int i = 1; i <= k; i++)
		denom *= i;

	int cb = num / denom;
	cout << "il coeff binomiale è " << cb;
}
