/* Definire una classe orologio che ha i seguenti metodi pubblici
a) costruttore per default, crea un orologio che segna la mezzanotte
b) void avanza(), fa avanzare l'orologio di un minuto
c) void visualizza(), visualizza l'orario corrente nella forma HH:MM */

#include <iostream>
//#include <cmath>
//#include <fstream>
//#include <random>
//#include <type_traits>
//#include <vector>

//#define

using namespace std;

//int constexpr N = 0;

class Orologio{
public:
	void avanza();
	void visualizza();
	Orologio();
private:
	int h, m;

};

Orologio::Orologio(){
	h=m=0;}

void Orologio::visualizza(){
	if(h<10)
		cout<<"0"<<h<<":";
	else
		cout<<h<<":";
	if(m<10)
		cout<<"0"<<m<<endl;
	else
		cout<<m<<endl;
}

void Orologio::avanza(){
	++m;}

int main(){
	Orologio o=Orologio();
	o.visualizza();
	o.avanza();
	o.visualizza();
	for(int i=1; i<20; i++)
		o.avanza();
	o.visualizza();
}
