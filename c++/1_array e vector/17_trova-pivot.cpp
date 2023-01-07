/* legge una matrice quadrata di ordine N (ove
N è una costante definita con constexpr) e calcola il pivot, ossia il
più grande elemento in valore assoluto */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	constexpr int N=2;
	double m[N][N];
	double pivot = 0;

	for(int r=0; r < N; r++){
		for(int c=0; c < N; c++){
			cout << "inserisci elemento ";
			cin >> m[r][c];
		}
	}

	for(int r=0; r<N; r++){
		for(int c=0; c<N; c++){
			if (abs(m[r][c])>pivot)
				pivot = m[r][c];
		}
	}
	
	cout << "il pivot è " << pivot << endl;
}
// non funziona con elementi negativi
//cout << setw(4) << x;


