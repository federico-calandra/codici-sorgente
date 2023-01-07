/* legge gli elementi di due array a e b di N numeri
interi e ricopia in un array c di 2N numeri interi prima gli elementi
di a poi quelli di b */

#include <iostream>
#define N 4

using namespace std;

int main(){

	double a[N], b[N];
	
	cout << "inserisci a\n";
	for(int i=0; i<N; i++)
		cin >> a[i];
	
	cout << "inserisci b\n";
	for(int i=0; i<N; i++)
		cin >> b[i];
	
	double c[2*N];

	for(int i=0; i<N; i++)
		c[i] = a[i];
	
	for(int i=N; i<2*N; i++)
		c[i] = b[i-N];
	
	for(int i=0; i<2*N; i++)
		cout << c[i] << " ";
}
