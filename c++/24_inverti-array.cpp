/* legge i dati di un array di N stringhe, li
copia in un secondo array in ordine inverso e infine scrive sullo
schermo il secondo array */

#include <iostream>
# define N 2

using namespace std;

int main(){
	string a[N], b[N];

	cout << "inserisci a\n";
	for(int i=0; i<N; i++)
		cin >> a[i];

	for(int i=0; i<N; i++){
	b[i] = a[N-i];
	}
	
	cout << a << endl << b;
}
