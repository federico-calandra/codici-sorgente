/* Definire una classe Veicolo che rappresenta un veicolo avente una targa e posizione geografica (latitudine e longitudine), un costruttore che crea un veicolo con una data targa e una data posizione e due metodi: sposta e visualizza.
Definire una classe Camion che estende Veicolo, aggiungendo un campo contenuto di tipo stringa e un campo carico di tipo double, un metodo carica e un metodo scarica.
Facoltativo: ridefinire il metodo visualizza */

#include <iostream>

using namespace std;

// DICHIARAZIONE CLASSI
class Veicolo{
public:
	void sposta(double x, double y);
	void visualizza();
	Veicolo(string targa, double x, double y);
	Veicolo();

private:
	string targa;
	double x;
	double y;
};


class Camion: public Veicolo{
public:
	void carica(double carico);
	void scarica(double carico);
	void visualizza();
	Camion();
	Camion(string targa, double x, double y, string contenuto, double carico);
private:
	string contenuto;
	double carico;
};

// IMPLEMENTAZIONE CLASSE VEICOLO
Veicolo::Veicolo(){
	x=y=0;
	targa="";
}

Veicolo::Veicolo(string t, double xx, double yy){
	x=xx;
	y=yy;
	targa=t;
}

void Veicolo::sposta(double xx, double yy){
	x=xx;
	y=yy;
}

void Veicolo::visualizza(){
	cout<<targa<<" "<<x<<" "<<y;
}

// IMPLEMENTAZIONE CLASSE CAMION
Camion::Camion(){
	contenuto="";
	carico=0;
}

Camion::Camion(string t, double xx, double yy, string c, double cc): Veicolo(t, xx, yy){
	contenuto=c;
	carico=cc;
}

void Camion::carica(double c){
	carico+=c;
}

void Camion::scarica(double c){
	carico-=c;
}

void Camion::visualizza(){
	Veicolo::visualizza();
	cout<<" contiene "<<carico<<" "<<contenuto<<endl;
}

// MAIN PROGRAM
int main(){
	Veicolo car1;
	Veicolo car2("aa000aa", 12, 4.2);

	car1.visualizza(); cout<<endl;
	car1.sposta(32,-42.2);
	car1.visualizza(); cout<<endl;

	car2.visualizza(); cout<<endl;


	Camion truck1;
	truck1.visualizza(); cout<<endl;
	truck1.carica(1.0);
	truck1.scarica(0.5);
	truck1.visualizza(); cout<<endl;
	truck1.sposta(10,-0.4);
	truck1.visualizza(); cout<<endl;

	Camion truck2("xx000zz", 37, -845, "gold", 1000);
	truck2.visualizza();
}
