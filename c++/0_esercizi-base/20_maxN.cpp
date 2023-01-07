/* legge n numeri reali da tastiera, ove n è un numero naturale inserito dall'utente, e visualizza alla fine il numero più grande.
Suggerimento: conservare in una variabile il valore più grande inserito
in quel momento e ad ogni numero letto da tastiera aggiornare tale variabile (quando è necessario) */

#include <iostream>

using namespace std;

int main()
{
	double x, max = 0;
	int n;

	cout << "inserisci numero di numeri ";
	cin >> n;

	cout << "inserisci numero ";
	cin >> x;
	max = x;
	for(int i=1; i<=n-1; i++){
		cout << "inserisci numero ";
		cin >> x;
		if(x>max)
			max = x;
	}
	cout << "massimo è " << x << endl;
}
