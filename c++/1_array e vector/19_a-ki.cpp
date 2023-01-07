/* legge da tastiera una matrice A di n x n elementi e un numero reale k e calcola la matrice B=A-k*I, ove I è la matrice identità. Ovviamente, n è una costante.   */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int constexpr n=2;
	double A[n][n];
	double I[n][n];
	double B[n][n];
	
	for(int r=0; r<n; r++)
		for(int c=0; c<n; c++){
			cout << " inserisci elemento ";
			cin >> A[r][c];}

	double k;	
	cout << " inserisci k ";
	cin >> k;

	for(int r=0; r<n; r++)
		for(int c=0; c<n; c++){
			if(r==c)
				I[r][c] = k;
			else
				I[r][c] = 0;}

	for(int r=0; r<n; r++)
		for(int c=0; c<n; c++)
			B[r][c] = A[r][c] - k * I[r][c];
	
	for(int r=0; r<n; r++){
		for(int c=0; c<n; c++)
			cout << B[r][c] << " ";
			cout << endl;}
}
