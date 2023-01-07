/* legge da tastiera una sequenza di numeri interi (terminata con il valore 0) e la visualizza in ordine inverso  */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	vector<int> seq;
	int n;	
	cout << "inserisci numero ";
	cin >> n;
	cout << n;
	while(n!=0){
		seq.push_back(n);
		cout << "inserisci numero ";
		cin >> n;
	}

	for(int i=seq.size()-1; i>=0; i--)
		cout << seq[i];
}
