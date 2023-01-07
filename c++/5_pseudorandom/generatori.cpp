/* comment */

#include <iostream>
#include <random>

using namespace std;

// genera n numeri pseudo-casuali ma ad ogni chiamata genera sempre gli stessi
void rand1(){
    minstd_rand gen1;

    uniform_real_distribution<double> unif(0,1);

    for(int i=1; i<=10; i++)
        cout<<unif(gen1)<<endl;
}

// impostando il seed vengono generati sempre numeri diversi
void rand2(){
    cout<<"inserisci seed ";
    double seed;
    cin>>seed;

    minstd_rand gen2;
    gen2.seed(seed);

    uniform_real_distribution<double> unif(0,1);

    for(int i=1; i<=10; i++)
        cout<<unif(gen2)<<endl;
}

//  l'impostazione del seed viene fatta prendendo un numero casuale
void rand3(){
    random_device seed;

    minstd_rand gen3;
    gen3.seed(seed());

    uniform_real_distribution<double> unif(0,1);

    for(int i=1; i<=10; i++)
        cout<<unif(gen3)<<endl;
}


int main(){
    rand1();
    rand2();
    rand3();
}
