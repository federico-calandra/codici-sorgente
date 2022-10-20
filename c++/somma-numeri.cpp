/*  */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cout << "inserisci n ";
	cin >> n;
	
	double s = 0;
	double x;
	
	for(int i = 1; i <= n; i++)
	{
		cout << "inserisci numero da sommare ai precedenti\n";
		cin >> x;
		s += x;
	}
	
	cout << "la somma è " << s;
}
