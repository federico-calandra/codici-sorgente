/* Scrivere un programma che genera a caso N numeri reali compresi tra 0 e 1 usando una distribuzione uniforme, li visualizza e ne calcola la media e la varianza.
Per generare 1 numero a caso
Includere <random>
Definire un generatore con la dichiarazione
minstd_rand   gen;
Definire una distribuzione con la dichiarazione
uniform_real_distribution<double> unif(0,1)
Il numero si genera con            unif(gen) */

#include <iostream>
//#include <cmath>
//#include <vector>
#include <random>

using namespace std;

//int constexpr N = 0;


vector<double> rand(int num){

    random_device seed;
    minstd_rand gen;
    gen.seed(seed());

    uniform_real_distribution<double> unif(0,1);

    int n = num;
    vector<double> rnd;
    for(int i=1; i<=n; i++)
        rnd.push_back(unif(gen));

    return rnd;
}

double media(vector<double> v){
    double m = 0;

	for(int i=0; i<v.size(); i++)
		m += v[i];
	m /= v.size();

	return m;
}

double deviaz(vector<double> v){
    double m = media(v);
    double s = 0;

	for(int i=0; i<v.size(); i++)
		s += pow(v[i]-m,2);
	s /= v.size();
    s = pow(s,0.5);

	return s;
}

int main(){

    vector<double> numeri;
    int num;
    cin>>num;

    numeri=rand(num);
    for(int i=0; i<num; i++)
        cout<<numeri[i]<<" ";
    cout<<endl;

    cout<<media(numeri)<<endl<<deviaz(numeri);
}
