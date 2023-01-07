/* Definire una struct a vostro piacimento, definire una funzione crea, una funzione visualizza, una funzione modifica.
Scrivere il main che crea un esemplare della struct tramite la funzione crea, lo modifica, lo visualizza e lo distrugge con delete. */

#include <iostream>
#include <type_traits>
//#include <cmath>
//#include <vector>

using namespace std;

//int constexpr N = 0;

struct persona{
		string nome;
		int eta;
		double altezza;
	};

persona crea(string n, int e, double a){
	persona p={n, e, a};
	return p;
}

void visualizza(persona p){
	cout<<p.nome<<" "<<p.eta<<" "<<p.altezza<<endl;
}

void modifica(persona &p, string n, int e, double a){
	p.nome = n;
	p.eta = e;
	p.altezza = a;
}

int main(){

	persona io=crea("federico", 26, 1.80);
	visualizza(io);
	modifica(io, "federico", 26, 1.78);
	visualizza(io);

	persona *p = &io;
	delete(p);

}
