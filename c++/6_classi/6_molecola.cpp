/* Definire una classe Atomo che contiene alcuni dati di un atomo: simbolo dell’elemento chimico, massa atomica, numero atomico. La classe contiene un costruttore, un metodo che visualizza i dati e dei metodi dimmi_simbolo, dimmi_massa, dimmi_numero che restituiscono rispettivamente il simbolo, la massa e il numero atomico.
Definire una classe Molecola che è vista come sequenza di Atomi. La classe deve avere un costruttore che crea una molecola vuota, un metodo che aggiunge un atomo alla molecola, un metodo che visualizza la formula chimica della molecola e infine un metodo che restituisce la somma delle masse atomiche degli atomi che la compongono. */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Atomo{
private:
	string simbolo;
	double massa_atomica;
	int num_atomico;

public:
	Atomo(string simbolo, double massa, int numero);

	void info(){
		cout << simbolo << massa_atomica << num_atomico << endl;
	}

	string dimmi_simbolo();

	double dimmi_massa();

	int dimmi_numero();
};

Atomo::Atomo(string s, double m, int n){
	simbolo = s;
	massa_atomica = m;
	num_atomico = n;
}

string Atomo::dimmi_simbolo(){
	return simbolo;
}

double Atomo::dimmi_massa(){
	return massa_atomica;
}

int Atomo::dimmi_numero(){
	return num_atomico;
}


class Molecola{
	vector<Atomo> mol;
	string nome;

public:
	Molecola(string nome);

	void aggiungi_atomo(Atomo &atomo);

	double massa();

	int size();

	void formula();
};

Molecola::Molecola(string n){
	nome = n;
}

int Molecola::size(){
	int s = mol.size();
	return s;
}

void Molecola::aggiungi_atomo(Atomo &a){
	mol.push_back(a);
}

void Molecola::formula(){
	for(int i=0; i < mol.size(); i++)
		cout << mol[i].dimmi_simbolo();
		cout << endl;
}

double Molecola::massa(){
	double m = 0;
	for(int i=0; i < mol.size(); i++)
		m+=mol[i].dimmi_massa();
	return m;
}

int main(){
	Atomo a1 = Atomo("As", 10.5, 5);
	Atomo a2 = Atomo("He", 0.04, 2);

	Molecola mol = Molecola("ratatat");

	mol.aggiungi_atomo(a1);
	mol.aggiungi_atomo(a2);
	mol.aggiungi_atomo(a2);

	cout<<mol.size()<<" atomi"<<endl;
	mol.formula();
	cout<<"massa "<<mol.massa()<<endl;
}

