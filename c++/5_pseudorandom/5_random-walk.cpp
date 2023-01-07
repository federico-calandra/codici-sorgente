/* Scrivere un programma che simula una “passeggiata aleatoria” (random walk) a una o a due dimensioni. C’è un punto che si muove in una retta o in un piano a passi unitari partendo dall’origine. Ad ogni istante di tempo sceglie a caso in che direzione muoversi (due direzioni per la retta e quattro per il piano). Calcolare due quantità:
a) la distanza dall’origine dopo T unità di tempo
b) il numero di unità di tempo necessarie a rientrare nell’origine */

#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int main()
{
	// inizializzo il generatore
	random_device s;
	minstd_rand gen;
	uniform_int_distribution dis(0,1);
	gen.seed(s());
	
	// posizione iniziale
	int constexpr N = 2;
	int pos[N] = {0, 0};
	
	// tempo di cammino
	int t;
	cout << "tempo di cammino ";
	cin >> t;
	
	// genero i due spostamenti
	for(int i=0; i<=10; i++){
		int x = (dis(gen)*2)-1;
		int y = (dis(gen)*2)-1;
		pos[0] += x;
		pos[1] += y;
	}

	// calcolo distanza 
	//double dist = ???;
	cout << "posizione è (" << pos[0] << ", "<< pos[1] << ")" << endl;
	//cout << "distanza percorsa " << dist << endl;
}
