// legge la temperatura dell'acqua e stabilisce lo stato di aggregazione, se definito

#include <iostream>

using namespace std;

int main()
{
	double temp;
	string stato;
	
	cout << "inserisci temperatura ";
	cin >> temp;
	
	// controllo se è in transizione di stato
	if(temp == 0 || temp == 100)
		cout << "lo stato è in transizione" << endl;

	// discrimino le possibilità
	else if(temp < 0)
		stato = "solido";
		else if(temp < 100)
				stato = "liquido";
			else if(temp > 100)
					stato = "gassoso";

	cout << "lo stato dell'acqua è " << stato << endl;
}

/* al posto di 0 e 100 potrei mettere le costanti temp_fusione e temp_evaporazione,
 * in questo modo posso usare sostanze diverse dall'acqua a patto di impostarne i valori */
