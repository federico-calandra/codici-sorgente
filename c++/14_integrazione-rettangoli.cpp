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
	// dovrei controllare che a<b e n>0

	//ris è il risultato dell'integrazione
	double ris = 0;
	// s è la lunghezza di ogni partizione
	double s = (b - a)/n;


	
	for(int i = 0; i<= n-1; i++)
		ris += (s * pow(a + (s/2) + (i*s),2));	// a seconda di f avrò una espressione diversa
	
	cout << "il risultato è " << ris;
}
