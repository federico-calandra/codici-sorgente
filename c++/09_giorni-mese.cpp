// chiede il numero di un mese e ne restituisce il # di giorni, con l'ipotesi di anno non bisestile

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int m, n;
	cout << "inserisci numero mese\n";
	cin >> m;
	
	// controllo validità della scelta
	if(m < 1 || m > 12)
		cout << "scelta non valida\n";
		
	// febbraio ha 28 giorni
	if(m == 2)
		n = 28;
	// aprile, giungo, settembre e novembre ne hanno 30
	else if(m == 4 || m == 6 || m == 9 || m == 11)
		n = 30;
	// i restanti ne hanno 31
	else
		n = 31;
		
	cout << "il mese ha " << n << " giorni\n";
}


