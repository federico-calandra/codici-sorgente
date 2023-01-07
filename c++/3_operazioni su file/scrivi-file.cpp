/* comment */

#include <iostream>
#include <fstream>

using namespace std;

int main(){

	fstream f;
	f.open("/home/federico/dati.txt", ios::out);

	for(double i=0; i<=10; i++)
		f<<i<<" "<<i*i<<" "<<i/2<<endl;

	f.close();
}









