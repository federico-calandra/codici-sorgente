/* Scrivere un programma che legge un file contenente i voti ottenuti dagli studenti di
un corso di laurea relativamente ad un singolo esame.
Il programma deve trovare il voto più frequente. */

#include <iostream>
//#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

//int constexpr N = 0;

double media(vector<double> &v){
	//calola media
}

int main(){

	fstream f;
	f.open("/home/federico/dati.txt", ios::in);

	vector<double> voti;

	while(!f.eof()){
		string n;
		double v;
		f>>n>>v;
		//cout<<v<<endl;
		voti.push_back(v);
	}

	for(int i=0;i<voti.size();i++)
		cout<<voti[i]<<endl;
}







