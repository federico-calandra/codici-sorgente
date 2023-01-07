/* legge gli elementi di due array u e v di N numeri reali
e due numeri reali a e b, calcola la combinazione lineare w=au+bv e scrive
il risultato w sullo schermo (come vettore colonna) */

#include <iostream>
#define N 3

using namespace std;

int main()
{
	double u[N], v[N], w[N], a, b;

	cout << "inserisci vettore u\n";
	for(int i=0; i<=N-1; i++)
		cin >> u[i];

	cout << "inserisci vettore v\n";
	for(int i=0; i<=N-1; i++)
		cin >> v[i];

	cout << "inserisci a e b ";
	cin >> a >> b;

	for(int i=0; i<=N-1; i++){
		u[i] *= a;
		v[i] *= b;}

	for(int i=0; i<=N-1; i++){
		w[i] = u[i] + v[i];
		cout << w[i] << endl;}
}
