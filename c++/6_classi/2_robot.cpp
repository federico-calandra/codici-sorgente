/* Scrivere una classe che rappresenta un robot. La classe ha almeno i campi privati posizione_x, posizione_y, theta (angolo che forma il robot rispetto all’asse x), stato del motore (acceso o spento). Il costruttore crea un robot posizionato nell’origine, con il motore spento e con theta=0.
La classe deve avere i seguenti metodi pubblici
    • void stato(), visualizza sullo schermo il risultato
    • void destra(theta1), gira il robot di theta1 gradi verso destra
    • void sinistra(theta1), gira il robot di theta1 gradi verso sinistra
    • void avanza(d), avanza il robot di d metri (se il motore è acceso) nella direzione theta
    • void accendi()
    • void spegni()
    • double distanza_percorsa(), restituisce la distanza totale percorsa in metri
Scrivere il main che crea un oggetto e chiama i vari metodi

2bis) aggiungere alla classe robot uno o più campi in modo tale che il robot memorizzi tutte le posizioni in cui è arrivato e un metodo che le visualizza sullo schermo*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Robot{
private:
	double pos[3];
	bool motore;
	double d_percorsa;
	vector<double> storia_x;
	vector<double> storia_y;

public:
	Robot();
	void stato();
	void destra(double theta);
	void sinistra (double theta);
	void avanza(double distanza);
	void accendi();
	void spegni();
	double distanza_percorsa();
	void storia_pos();
};

Robot::Robot(){
	pos[0]=pos[1]=pos[2]=0;
	storia_x.push_back(0);
	storia_y.push_back(0);
	motore=false;
	d_percorsa=0;
}


void Robot::stato(){
	if(motore==true)
		cout<<"motore acceso"<<endl;
	else
		cout<<"motore spento"<<endl;
}

void Robot::destra(double th){
	pos[2]-=th;
}

void Robot::sinistra(double th){
	pos[2]-=th;
}

void Robot::avanza(double d){
	if(motore==true){
		pos[0]+=d*cos(pos[2]);
		pos[1]+=d*sin(pos[2]);
		d_percorsa+=d;
		storia_x.push_back(pos[0]);
		storia_y.push_back(pos[1]);
	}
}

void Robot::accendi(){
	motore=true;
}

void Robot::spegni(){
	motore=false;
}

double Robot::distanza_percorsa(){
	return d_percorsa;
}

void Robot::storia_pos(){
	for(int i=0; i<storia_x.size(); i++)
		cout<<storia_x[i]<<" "<<storia_y[i]<<endl;
}

int main(){
	Robot r1 = Robot();
	r1.stato();
	r1.accendi();
	r1.sinistra(M_PI/4);
	r1.stato();
	r1.avanza(1);
	r1.sinistra(M_PI/4);
	r1.avanza(1);
	r1.spegni();
	r1.stato();
	r1.avanza(100);
	cout<<r1.distanza_percorsa()<<endl;
	r1.storia_pos();
}

