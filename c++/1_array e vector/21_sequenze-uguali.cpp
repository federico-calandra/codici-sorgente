/* legge due sequenze di numeri interi (terminate con 0 o con FINE, a vostro piacimento) e controlla se sono uguali (stessa dimensione e valori identici negli stessi posti) */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> seq1, seq2;
	
	int n;
	cout << "inserisci elemento sequenza 1 (0 per terminare) ";
	cin >> n;	
	while(n!=0){
		seq1.push_back(n);
		cout << "inserisci elemento sequenza 1 (0 per terminare) ";
		cin >> n;}

	cout << "inserisci elemento sequenza 2 (0 per terminare) ";
	cin >> n;	
	while(n!=0){
		seq2.push_back(n);
		cout << "inserisci elemento sequenza 2 (0 per terminare) ";
		cin >> n;}
	
	bool uguali;
	if(seq1.size() != seq2.size())
		uguali = false;
	else{
		uguali = true;
		for(int i=0; i<seq1.size(); i++)
			if(seq1[i]!=seq2[i]){
				uguali = false;
				break;}
	}

	if(uguali==false)
		cout << "sequenze non uguali" << endl;
	else
		cout << "sequenze uguali" << endl;
}
