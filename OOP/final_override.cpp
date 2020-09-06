#include<iostream>
using namespace std;

class A  
{
public: 
	virtual void Print(int i) {cout<<__PRETTY_FUNCTION__<<endl;}
};

class B : public A 
{
public: 
	void Print(int i) override  {cout<<__PRETTY_FUNCTION__<<endl;}
};

class C : public B
{
	void Print(int i) override {cout<<__PRETTY_FUNCTION__<<endl;}
};

int main () 
{
	A *obj = new C;
	obj->Print(20);
	obj->Print(30);

}