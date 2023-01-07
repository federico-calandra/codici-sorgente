/* Scrivere una funzione che calcola il valore di pi greco (approssimato) con il metodo Montecarlo. Il metodo usa un generatore di numeri pseudo-casuali. Quindi includere <random> e dichiarare una variabile globale di tipo minstd_rand (ad esempio con nome gen).
La funzione ha come parametro il numero n di punti da generare. Quindi genera n punti nel quadrato che come vertici (-1,1), (-1,-1), (1,1), (1,-1): è sufficiente generare la x e la y di ogni punto mediante la distribuzione dis dichiarata come
uniform_real_distribution<double> dis(-1,1);
e poi dare
x=dis(gen);
y=dis(gen);
Contare quanti punti hanno distanza dall’origine minore di 1, il rapporto con n è all’incirca pi greco/4. */

#include <iostream>
#include <cmath>
//#include <vector>
#include <random>

using namespace std;

//int constexpr N = 0;

vector<double> rand(int num){

    random_device seed;
    minstd_rand gen;
    gen.seed(seed());

    uniform_real_distribution<double> unif(-1,1);

    int n = num;
    vector<double> rnd;
    for(int i=1; i<=n; i++)
        rnd.push_back(unif(gen));

    return rnd;
}

double distanza(double x, double y){
    double xx=x, yy=y;
    return pow(xx*xx+yy*yy,0.5);
}

int main(){

    int n;
    cin>>n;

    vector<double> x;
    vector<double> y;

    x=rand(n);
    y=rand(n);

    int c=0;
    for(int i=0; i<n; i++){
        if(distanza(x[i],y[i])<1)
            c++;
    }
    cout<<c<<endl;
    cout<<n<<endl;
    double pi = 4*double(c)/n;
    cout<<pi<<endl;
}
