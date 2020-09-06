#include<iostream>
#include<string>


using namespace std;
class A 
{
public: 
	A() {cout<<__PRETTY_FUNCTION__<<endl;}
	~A() {cout<<__PRETTY_FUNCTION__<<endl;}
};

class B
{
public: 
	B() {cout<<__PRETTY_FUNCTION__<<endl;}
	~B() {cout<<__PRETTY_FUNCTION__<<endl;}
};

union UDT
{
	A a;
	B b;
	// Have to implement ctor 
	UDT() {cout<<__PRETTY_FUNCTION__<<endl;}
	~UDT() {cout<<__PRETTY_FUNCTION__<<endl;}
};
main () 
{
	UDT uObj;
	// have to create a b with placement new operator 
	// memory of a and b is already allocated by ctor need to be called
	new(&uObj.a) A{};
	new(&uObj.b) B{};
	// have to delete a and b manually
	uObj.a.~A();
	uObj.b.~B();
}