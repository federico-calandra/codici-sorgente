/* legge N numeri reali e controlla se sono ordinati in senso crescente. Suggerimento: contare quanti sono gli elementi minori o uguali al loro predecessore nell’array (o nel vector) */

#include <iostream>

using namespace std;

int main()
{
	int n=5;
	double seq[n];
	
	for(int i=0; i<n; i++){
		cout << " inserisci elemento ";
		cin >> seq[i];}
	
	bool ord = true;	
	for(int i=1; i<n; i++)
		if(seq[i]<=seq[i-1]){
			ord = false;
			break;}

	if(ord==false)
		cout << "sequenza non ordinata" << endl;
	else
		cout << "sequenza ordinata" << endl;
}
