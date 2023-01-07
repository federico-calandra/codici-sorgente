/* Scrivere un programma che legge un insieme di dati da un file. L’insieme è composto da tre colonne separate da virgole. Ogni riga corrisponde ai risultati di un esperimento: nella prima colonna c’è un numero progressivo, nella seconda colonna c’è il tempo in secondi e nella terza colonna c’è una lunghezza in cm.
Il programma deve scrivere sullo schermo i seguenti dati
    a) Numero di righe lette
    b) Media e deviazione standard del tempo
    c) Media e deviazione standard della lunghezza
    d) Coefficienti della retta di regressione tra lunghezza e tempo */

#include <iostream>
//#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

//int constexpr N = 0;

double media(vector<double> &v){
	//calola media
}

double devstd(vector<double> &v){
	//calola deviaz std
}

int main(){

	fstream f;
	f.open("/home/federico/dati.txt", ios::in);

	int n_righe = 0;
	vector<double> t, l;

	while(!f.eof()){
		int kk;
		double tt, ll;
		f>>kk>>tt>>ll>>ws;
		t.push_back(tt);
		l.push_back(ll);
		n_righe++;
	}

	double mu=media(t);
	double sigma=devstd(t);
	cout<<n_righe<<mu<<sigma<<endl;
}







