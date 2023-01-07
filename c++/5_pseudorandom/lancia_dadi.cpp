/* comment */

#include <iostream>
#include <random>

using namespace std;

vector<int> lancia_dadi(int n){
	random_device s;
	
	minstd_rand gen;	
	gen.seed(s());
	uniform_int_distribution<int> unif(1,6);
	
	vector<int> lancio;
	for(int i=1; i<=n ;i++)
		lancio.push_back(unif(gen));
		
	return lancio;
}

int massimo(vector<int> v){
	int max = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i]>max)
			max = v[i];
	}
	return max;
}
	
double media(vector<int> v){
	double m = 0;
	for(int i=0; i<v.size(); i++)
		m += v[i];
	m /= v.size();
	return m;
}

int main()
{
	int k;
	cout << "numero di dadi ";
	cin >> k;
	
	int n;
	cout << "numero di lanci ";
	cin >> n;
	
	// vector dove viene salvato il massimo di ogni lancio
	vector<int> massimi;
	
	// faccio n lanci di k dadi
	for(int i=1; i<=n; i++){
		// lancio k dadi e li visualizzo
		vector<int> lancio = lancia_dadi(k);
		/*for(int j=0; j<lancio.size(); j++){
			cout << lancio[j] << " ";
			cout << endl;}*/
		// calcolo il massimo, lo salvo e lo visualizzo
		int max = massimo(lancio);
		massimi.push_back(max);
		//cout << "massimo è " << max << endl;
	}
	
	// faccio la media dei massimi salvati
	double med = media(massimi);
	cout << "media è "<< med << endl;
}
