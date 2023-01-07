/* legge i coefficienti di un polinomio p in 
un vector e un numero reale x e calcola il valore del polinomio p' nel punto x */

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
	
	double a, b;
	cout << "inserisci estremi di integrazione ";
	cin >> a >> b;

	double ris = 0;
	for(int i=0; i <= n+1; i++)
		ris += coeff[i] / (i+1) * pow(b,i+1);

	for(int i=0; i <= n+1; i++)
		ris -= coeff[i] / (i+1) * pow(a,i+1);		
		
	cout << ris;
}
