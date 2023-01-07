/* visualizza sullo schermo una tabella con 3 colonne, ella prima ci sono gli angoli da 0 a 90 con passo 5, nella seconda il valore del seno e nella terza il valore del coseno */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	for(float a = 0; a <= M_PI/2; a += M_PI/36)
		cout << a << "    " << sin(a) << "    " << cos(a) << endl;
}
