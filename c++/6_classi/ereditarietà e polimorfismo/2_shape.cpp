/* Create a simple “shape” hierarchy: a base class called Shape and derived classes called Circle, Square, and Triangle. In the base class, make a virtual function called draw( ), and override this in the derived classes. Make an array of pointers to Shape objects that you create on the heap (and thus perform upcasting of the pointers), and call draw( ) through the base-class pointers, to verify the behavior of the virtual function. If your debugger supports it, single-step through the code. */

#include <iostream>

using namespace std;

class Shape{
public:
	virtual void draw(){cout<<"shape"<<endl;};
	Shape(){}
};


class Circle:public Shape{
public:
	void draw(){cout<<"cerchio"<<endl;}
	Circle(){}
};


class Square:public Shape{
public:
	void draw(){cout<<"quadrato"<<endl;}
	Square(){}
};


class Triangle:public Shape{
public:
	void draw(){cout<<"triangolo"<<endl;}
	Triangle(){}
};


int main(){
	Shape* arr[4];
	arr[0]=new Shape();
	arr[1]=new Circle();
	arr[2]=new Square();
	arr[3]=new Triangle();

	for(int i=0;i<=3;i++)
		arr[i]->draw();
}
