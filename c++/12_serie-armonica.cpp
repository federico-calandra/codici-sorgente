/* comment */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, k;
	cout << "inserisci n ";
	cin >> n;
	
	cout << "inserisci k ";
	cin >> k;
	
	if(n < k)

	double s = 0;

	for(int i=1; i <= n; i++)
	{
		s = s + pow(i,-2);
	}
	
	cout << "la somma è " << s;
}
