/* Scrivere un programma che genera n numeri pseudo-casuali con distribuzione con media mu e varianza sigma2
normal_distribution<double> dis(mu, sigma2);
e ne calcola media e varianza. */

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
