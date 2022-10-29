/* legge gli elementi di un array di N numeri reali,
ne calcola la media quadratica e scrive sullo schermo il risultato */

#include <iostream>
#define N 5

using namespace std;

int main()
{
	double x[N], mediaq = 0;

	for(int i=0; i<=N-1; i++){
		cout << "inserisci elemento ";
		cin >> x[i];
	}


	for(int i=0; i<=N-1; i++){
		mediaq += x[i]*x[i];
	}

	mediaq /= N;
	cout << "media quadratica è " << mediaq << endl;
}
