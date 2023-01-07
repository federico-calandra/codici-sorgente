/* legge i coefficienti di un polinomio p in 
un vector e un numero reale x e calcola il valore del polinomio p nel punto x */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n;
	cout << "inserisci grado polinomio ";
	cin >> n;
	
	vector<int> coeff(n+1);
	for(int i=0; i <= n; i++){
		cout << "inserisci coefficiente ";
		cin >> coeff[i];
	}
	
	double x;	
	cout << "inserisci punto di cui valutare ";
	cin >> x;
	
	double ris = 0;
	for(int i=0; i <= n; i++)
		ris += coeff[i] * pow(x,i);
		
	cout << ris;
}
