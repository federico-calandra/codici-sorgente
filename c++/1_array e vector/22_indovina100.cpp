/* genera a caso un numero intero tra 1 e 100 e poi chiede all’utente di indovinarlo, con un numero massimo di tentativi. Ad ogni tentativo il programma indica se il numero inserito è maggiore, minore o uguale a quello generato. In quest’ultimo caso il programma si ferma dopo essersi congratulato con l’utente. Invece, se l’utente non riesce a vincere, il programma rivela il numero generato. */

#include <iostream>

using namespace std;

int main()
{
	int numero = 1 + time(0) % 100;
	int guess;
	int i = 1;
	bool indovinato = false;
	
	while(i<=5 && indovinato==false){
		cout << "indovina numero fra 1 e 100 con max 5 tentativi (" << i << "/5) ";
		cin >> guess;
		
		if(guess==numero){
			indovinato = true;
			break;}
		else if(guess > numero)
			cout << "il numero è minore" << endl;
		else
			cout <<"il numero è maggiore" << endl;
		i++;
	}
	
	if(indovinato==true)
		cout << "indovinato il numero "<< numero << " con " << i << " tentativi" << endl;
	else
		cout << "il numero da indovinare è " << numero << endl;
}
