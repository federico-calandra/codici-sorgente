/* riempe una matrice quadrata di ordine N (ove
N è una costante definita con constexpr) nel seguente modo:
gli elementi della diagonale principale sono uguali a 0
gli elementi al di sopra della diagonale sono 1
gli elementi al di sotto della diagonale sono -1 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	constexpr int N=10;

	double m[N][N];

	for(int r=0; r < N; r++){
		for(int c=0; c < N; c++){
			if(r==c)
				m[r][c] = 0;
			else if (c>r)
				m[r][c] = 1;
			else if(r>c)
				m[r][c] = -1;
		}
	}

	for(int r=0; r < N; r++){
		for(int c=0; c < N; c++){
			cout << m[r][c];
		}
		cout << endl;
	}
}
