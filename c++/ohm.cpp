// chiede quale forma della legge di Ohm usare (I=V/R V=RI R=V/I), poi chiede il valore delle grandezze indipendenti e calcola la restante grandezza


#include <iostream>

using namespace std;

int main()
{
	cout << "scegli forma da usare\n";
	cout << "1) I=V/R\n";
	cout << "2) V=R*I\n";
	cout << "3) R=V/I\n\n";
	
	int s;
	cin >> s;
	
	double res;
	
	// controllo validità della scelta
	if(s != 1 || s != 2 || s != 3)
		cout << "scelta non valida" << endl;
	
	// per ongi scelta chiede gli input e calcola il risultato con unità di misura
	if(s == 1){
		double V, R;
		cout << "inserisci V e R\n";
		cin >> V >> R;
		res = V/R;
		cout << "il risultato è " << res << " A" << endl;}
	else if(s == 2){
		double R, I;
		cout << "inserisci R e I\n";
		cin >> R >> I;
		res = R*I;;
		cout << "il risultato è " << res << " V" << endl;}
	else if(s == 3){
		double V, I;
		cout << "inserisci V e I\n";
		cin >> V >> I;
		res = V/I;;
		cout << "il risultato è " << res << " Ω" << endl;}
	
}
