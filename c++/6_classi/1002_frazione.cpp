#include <iostream>

using namespace std;

class Frazione{
public:
	Frazione operator+(Frazione& f2);
	Frazione operator-(Frazione& f2);
	Frazione operator*(Frazione& f2);
	Frazione operator/(Frazione& f2);
	friend ostream& operator<<(ostream& s, const Frazione& f);
	friend istream& operator>>(istream& s, Frazione& f);
	Frazione(int num, int den);
	Frazione();

private:
	void semplifica();
	int num, den;
};


Frazione::Frazione(){
	num=den=0;}

Frazione::Frazione(int n, int d){
	num=n; den=d;}

ostream& operator<<(ostream& s,const Frazione& f){
	if(f.num==f.den)
		cout<<1<<endl<<endl;
	else if(f.den==1)
		cout<<f.num<<endl<<endl;
	else
		cout<<f.num<<endl<<"---"<<endl<<f.den<<endl<<endl;
	return s;
}

istream& operator>>(istream& s, Frazione& f){
	s>>f.num>>f.den;
	return s;
}

Frazione Frazione::operator+(Frazione& f2){
	int n=num*f2.den+den*f2.num;
	int d=den*f2.den;
	Frazione r(n,d);
	r.semplifica();
	return r;
}

Frazione Frazione::operator-(Frazione& f2){
	int n=num*f2.den-den*f2.num;
	int d=den*f2.den;
	Frazione r(n,d);
	r.semplifica();
	return r;
}

Frazione Frazione::operator*(Frazione& f2){
	int n=num*f2.num;
	int d=den*f2.den;
	Frazione r(n,d);
	r.semplifica();
	return r;
}

Frazione Frazione::operator/(Frazione& f2){
	int n=num*f2.den;
	int d=den*f2.num;
	Frazione r(n,d);
	r.semplifica();
	return r;
}

void Frazione::semplifica(){
	if(num>den){
		if(num%den==0){
			num/=den;
			den=1;}
	}
	else if(num<den){
		if(den%num==0){
			den/=num;
			num=1;}
	}
	else{
		num=den=1;
	}
}


int main(){
	Frazione f1, f2;
	cin>>f1>>f2; cout<<endl;

	Frazione s=f1+f2; cout<<"f1+f2"<<endl<<s;
	Frazione d=f1-f2; cout<<"f1-f2"<<endl<<d;
	Frazione p=f1*f2; cout<<"f1*f2"<<endl<<p;
	Frazione q=f1/f2; cout<<"f1/f2"<<endl<<q;
}
