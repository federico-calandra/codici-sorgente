/* visualizza sullo schermo una tabella con 3 colonne, ella prima ci sono gli angoli da 0 a 90 con passo 5, nella seconda il valore del seno e nella terza il valore del coseno */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	for(int angolo = 0; angolo <= 90; angolo += 5){
		double rad = 180 * M_PI / angolo;
		cout << angolo << "    " << sin(rad) << "    " << cos(rad) << endl;
	}
}
