/* Definire una classe generica pezzo che serve a memorizzare la posizione di un pezzo degli scacchi nella scacchiera. Definire due metodi virtuali e astratti:
bool sposta(x,y) che prova a spostare il pezzo nella posizione (x,y) (immaginando una scacchiera vuota) e restituisce true se il pezzo si può muovere in (x,y), e in tal caso sposta il pezzo, false altrimenti.
// void descriviti(), che scrive sullo schermo la posizione del pezzo
Definire alcune classi figlie della classe pezzo che implementano alcuni pezzi della scacchiera (torre, alfiere, pedone…).
Infine scrivere il main che permette di spostare alcuni pezzi.*/

#include <iostream>

using namespace std;

// DICHIARAZIONE CLASSE PEZZO
class petType{
public:
    virtual void print();
    petType(string n = "");
private:
    string name;
};

class dogType: public petType{
public:
    void print();
    dogType(string n = "", string b = "");
private:
    string breed;
};

petType::petType(string n)
{
name = n;
}

// MAIN PROGRAM
int main(){
    ///Pedone p1=Pedone(2,3);
}
