/* comment */

#include <iostream>

using namespace std;

int main(){
	double m=10.0;
	double *p;
	p=&m;
	*p=0.42;
	cout<<m;
}
