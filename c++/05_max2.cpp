e// chiede due numeri e restituisce il maggiore

#include <iostream>

using namespace std;

int main()
{
	double x1, x2;
	double max;
	
	cout << "inserisci due numeri\n";
	cin >> x1 >> x2;
	
	// se sono uguali scelgo x1 come massimo
	if (x1 >= x2)	{
		max = x1; }
	else	{
		max = x2; }
	cout << "il maggiore fra i due è " << max << endl;
}
