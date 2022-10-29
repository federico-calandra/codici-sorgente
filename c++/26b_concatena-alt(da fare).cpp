/* legge gli elementi di due array a e b di N numeri
interi e ricopia in un array c di 2N numeri interi in modo alternato gli elementi
e quelli di b */

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

	//

	for(int i=0; i<2*N; i++)
		cout << c[i] << " ";
}
