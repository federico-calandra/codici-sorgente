/* integra numericamente f(x) = x² con il metodo dei trapezi f(x1) + f(x2))*h/2 */

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
	double s = (b-a)/n;
	/* ho bisogno di f valutata agli estremi di ogni partizione
	 * quindi f(i*a) e f(i*a+s) con i da a  */
	
	for(int i = 0; i <= n; i++)
		ris += s / 2 * ( pow(a + i*s,2) + pow(a + (i+1)*s,2) ); // è l'area dell'i-esimo trapezio
	
	cout << "il risultato è " << ris;
}
