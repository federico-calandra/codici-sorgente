/* legge gli elementi di due array x e y di N numeri reali
e calcola i coefficienti della retta di regressione y=b+ax di y rispetto a x */

#include <iostream>
# define N 6

using namespace std;

int main(){
	double x[N], y[N];

	cout << "inserisci x\n";
	for(int i=0; i<N; i++)
		cin >> x[i];
		
	cout << "inserisci y\n";
	for(int i=0; i<N; i++)
		cin >> y[i];
		
	double xm = 0, ym = 0;
	for(int i=0; i<N; i++){
		xm += x[i];
		xm /= N;
	}
	for(int i=0; i<N; i++){
		ym += y[i];
		ym /= N;
	}
	
	double cov = 0, var = 0;
	for(int i=0; i<N; i++)
		cov += (x[i] - xm) * (y[i] - ym);
	for(int i=0; i<N; i++)
		var += pow((x[i] - xm),2);
	
	double a = cov / var;
	double b = ym - (a*xm);
	
	cout << a << endl << b;
}
