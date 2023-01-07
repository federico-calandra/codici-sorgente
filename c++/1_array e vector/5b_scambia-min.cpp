/* legge i dati di un array di N numeri interi
trova l'indice dell'elemento più piccolo e scambia di posto il primo
elemento con l'elemento più piccolo */

#include <iostream>
#define N 4

using namespace std;

int main(){

	cout << "inserisci a\n";
	int a[N];
	for(int i=0; i<N; i++)
		cin >> a[i];
	

	int min = a[0], posmin = 0;
	for(int i=1; i<N; i++){
		if(a[i] < min){
			min = a[i];
			posmin = i;
		}
	}
	
	int z = a[0];
	a[0] = min;
	a[posmin] = z;
	
	for(int i=0; i<N; i++)
		cout << a[i] << " ";
}
