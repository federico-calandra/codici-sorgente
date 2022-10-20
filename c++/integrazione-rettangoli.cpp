/* integra numericamente f(x) = x² con il metodo dei rettangoli (int ≈ sum_i s*f(m_i)) */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b;
	cout << "inserisci estremi di integrazione\n";
	cin >> a >> b;
	
	int n;
	cout << "inserisci nuemero di partizioni\n";
	cin >> n;
	
	double s = (b - a)/n;
	// dovrei controllare che a<b e n>0

	double ris = 0;
	
	for(int i = 0; i<= n-1; i++)
	ris += (s * pow(a + (s/2) + (i*s),2));	// a seconda di f avrò una espressione diversa
	
	cout << "il risultato è " << ris;
}
