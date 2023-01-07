/* comment */

#include <iostream>
#include <cmath>
#include <vector>
//#include <random>

using namespace std;


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

}
