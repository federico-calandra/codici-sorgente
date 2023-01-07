/* legge un numero naturale n e controlla
se n è un numero primo, verificando che non abbia divisori propri
(un numero d è un divisore proprio di n se d divide n e d non è 1 né n). */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cout << "inserisci numero ";
	cin >> n;
	bool primo = true;
	int d = 2;

	while(primo==true && d<n){
		if(n%d == 0){
			primo = false;
			break;}
		else
			d++;
	}
	
	if(primo==false)
		cout << n << " non è primo, il primo divisore è " << d << endl;
	else
		cout << n << " è primo" << endl;
	
}
