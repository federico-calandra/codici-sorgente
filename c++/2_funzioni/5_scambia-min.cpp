/* Definire una funzione che dati come parametri un array di numeri interi
e la sua dimensione, modifica l'array scambiando di posto il primo
elemento con l'elemento più piccolo. La funzione non avendo risultati deve essere di tipo void.
Scrivere il main che legge i dati del problema, chiama la funzione e scrive
sullo schermo il nuovo contenuto dell'array. */

#include <iostream>
#include <cmath>

using namespace std;
int constexpr N = 5;

void scambiaMin(int a[], int N){
    int pos = 0;
    int min = a[pos];
    for(int i=1; i<N; i++)
        if(a[i] < min){
            pos = i;
            min = a[i];}

    int a0 = a[0];
    a[0] = a[pos];
    a[pos] = a0;
}

int main(){
    int vec[N];
    for(int i=0; i<N; i++){
        int x;
        cout << "inserisci valore" << endl;
        cin >> x;
        vec[i] = x;
    }

    scambiaMin(vec, N);

    for(int i=0; i<N; i++)
        cout << vec[i];
}
