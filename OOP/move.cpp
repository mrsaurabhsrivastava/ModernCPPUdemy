#include<iostream>
using namespace std;


// Rule of 5 
// Destructor 
// Copy Ctor
// Copy assignment operator 
// Move ctor
// Move assignment operator
class Integer
{
public:
	Integer() 
	:Integer(0)
	{
		
	}
	Integer(int i)
	{
		cout<<"Integer created"<<endl;
		mPtr = new int(i);
	}

	Integer(const Integer& obj)
	{
		cout<<"Copy ctor called"<<endl;
		mPtr = new int(obj.GetValue());
	}

	Integer(Integer &&obj) 
	{
		cout<<"Move ctor called"<<endl;
		mPtr = obj.mPtr;
		obj.mPtr = nullptr;
	}
	~Integer()
	{
		cout<<"Integer deleted with ptr="<<mPtr<<endl;
		delete mPtr;
	}

	int GetValue() const {return *mPtr;}
	void SetValue(int i) {*mPtr = i;}
private: 
	int* mPtr;
};

Integer Add (const Integer &a, const Integer &b)
{
	Integer tmp;
	tmp.SetValue(a.GetValue() + b.GetValue());
	return tmp;
}
Integer Add(int a , int b)
{
	Integer tmp(a+b);
	return tmp;
}
int main () 
{
	//Integer a = 5;
	//Integer a(10), b(11);
	//a.SetValue(Add(a,b).GetValue());
	Integer x = Add(3,4);
}