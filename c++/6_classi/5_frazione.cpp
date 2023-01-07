/*    */

#include <iostream>
#include <cmath>

using namespace std;

class frazione{
	int num, den;

public:
	frazione(int n,int d);

	frazione(int d);

	void scrivi(){
		cout<<num<<"/"<<den<<endl;
	}

	//versione interna
	frazione somma_con(frazione &f2);

	//versione statica
	static frazione somma(frazione &f1, frazione &f2);

	static frazione sottrai(frazione &f1, frazione &f2);

	static frazione moltiplica(frazione &f1, frazione &f2);

	static frazione dividi(frazione &f1, frazione &f2);
};

frazione::frazione(int n,int d){
	num=n;
	den=d;
}

frazione::frazione(int d){
	num = 1;
	den = d;
}

frazione frazione::somma_con(frazione &f2){
	int n3=num*f2.den+den*f2.num;
	int d3=den*f2.den;
	frazione f3(n3,d3);
	return f3;
}

//versione statica
frazione frazione::somma(frazione &f1, frazione &f2){
	int n3=f1.num*f2.den+f1.den*f2.num;
	int d3=f1.den*f2.den;
	frazione f3(n3, d3);
	return f3;
}

frazione frazione::sottrai(frazione &f1, frazione &f2){
	int n3 = f1.num*f2.den - f1.den*f2.num;
	int d3 = f1.den*f2.den;
	frazione f3(n3, d3);
	return f3;
}

frazione frazione::moltiplica(frazione &f1, frazione &f2){
	int n3 = f1.num*f1.num;
	int d3 = f1.den*f2.den;
	frazione f3(n3, d3);
	return f3;
}

frazione frazione::dividi(frazione &f1, frazione &f2){
	int n3 = f1.num*f2.den;
	int d3 = f1.den*f2.num;
	frazione f3(n3, d3);
	return f3;
}


int main() {
	frazione a(3,4), b(5,6);

	frazione c = a.somma_con(b);
	c.scrivi();

	frazione d = frazione::dividi(a,b);
	d.scrivi();
}
