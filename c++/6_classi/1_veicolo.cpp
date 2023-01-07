/* Scrivere una classe che rappresenta un veicolo. La classe ha i campi privati targa, posizione e quantità di carburante. Definire un costruttore che crea un veicolo con una data targa, posizionato nell’origine e con serbatoio vuoto.
La classe deve i metodi:
void riempi_serbatoio(k), riempe il serbatoio di k litri di carburante
void scrivi_dati(), visualizza i dati
void spostati(x,y,r), sposta il veicolo nella posizione (x,y) consumando k litri di carburante.
Scrivere un main che crea un oggetto della classe e chiama i metodi (ad esempio tramite un menù). */

#include <iostream>

using namespace std;

class Veicolo{
private:
	string targa;
	double pos[2];
	double carb;

public:
	Veicolo(string targa);
	void riempi_serbatoio(double carb);
	void scrivi_dati();
	void spostati(double x, double y, double k);
};

Veicolo::Veicolo(string t){
	targa = t;
	pos[0] = pos[1] = 0;
	carb = 0;
}

void Veicolo::riempi_serbatoio(double k){
	carb += k;
}

void Veicolo::scrivi_dati(){
	cout << "targa " << targa << endl;
	cout << "posizione " << pos[0] << ", " << pos[1] << endl;
	cout << "carburante " << carb << endl;
}

void Veicolo::spostati(double x, double y, double k){
	pos[0] = x;
	pos[1] = y;
	carb -= k;
}

int main(){

}
