/* Definire una classe generica pezzo che serve a memorizzare la posizione di un pezzo degli scacchi nella scacchiera. Definire due metodi virtuali e astratti:
bool sposta(x,y) che prova a spostare il pezzo nella posizione (x,y) (immaginando una scacchiera vuota) e restituisce true se il pezzo si può muovere in (x,y), e in tal caso sposta il pezzo, false altrimenti.
// void descriviti(), che scrive sullo schermo la posizione del pezzo
Definire alcune classi figlie della classe pezzo che implementano alcuni pezzi della scacchiera (torre, alfiere, pedone…).
Infine scrivere il main che permette di spostare alcuni pezzi.*/

#include <iostream>

using namespace std;

// DICHIARAZIONE CLASSE PEZZO
class Pezzo{
public:
    virtual bool sposta();
    //void getInfo();
    Pezzo();

protected:
    int xpos;
    int ypos;
};

// DICHIARAZIONE CLASSE PEDONE
class Pedone: public Pezzo{
public:
    bool sposta();
    //void getInfo();
    Pedone(int xpos, int ypos);
protected:
    string tipo;
};


// IMPLEMENTAZIONE CLASSE PEZZO
Pezzo::Pezzo(){
    xpos=0; ypos=0;}

/*void Pezzo::getInfo(){
    cout<<"pos: ("<<xpos<<", "<<ypos<<")";}*/


// IMPLEMENTAZIONE CLASSE PEDONE
Pedone::Pedone(int xp, int yp){
    xpos=xp; ypos=yp;
    tipo = "pedone";}

/*void Pedone::getInfo(){
    Pezzo::getInfo();
    cout<<" tipo: "<<tipo<<endl;
}

bool Pedone::sposta(){}*/



// MAIN PROGRAM
int main(){
    ///Pedone p1=Pedone(2,3);
}
