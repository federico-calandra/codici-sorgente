/* Modify 2) so draw() is a pure virtual function. Try creating an object of type Shape. Try to call the pure virtual function inside the constructor and see what happens. Leaving it as a pure virtual, give draw() a definition. */

#include <iostream>

using namespace std;

class Shape{
public:
	virtual void draw()=0;
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
	//arr[0]=new Shape();
	arr[1]=new Circle();
	arr[2]=new Square();
	arr[3]=new Triangle();

	for(int i=0;i<=3;i++)
		arr[i]->draw();
}
