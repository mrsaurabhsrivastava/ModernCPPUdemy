#include<iostream>
using namespace std;

// if operator are overloaded as global function 
// it require no of argument as the operands
// If operator are oveloaded as member function 
// one argumnet is passed implicitly by this pointer

// class operator get priority over global function
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

	Integer& operator=(const Integer& x)
	{
		if (&x != this)
		{	
			delete mPtr;
			mPtr = new int(x.GetValue());
		}
		return *this;
	}

	Integer& operator==(Integer&& x)
	{
		if(&x != this)
		{
			delete mPtr;
			mPtr = x.mPtr;
			x.mPtr = nullptr;		
		
		}
		return *this;
	}
	~Integer()
	{
		cout<<"Integer deleted with ptr="<<mPtr<<endl;
		delete mPtr;
	}

	Integer operator+(const Integer& x) const
	{
		return Integer(GetValue() + x.GetValue());
	}

	Integer& operator++()
	{
		++(*mPtr);
		return *this;
	}

	Integer operator++(int)
	{
		Integer tmp(this->GetValue());
		++(*mPtr);
		return tmp;
	}

	bool operator==(const Integer& x) const 
	{
		return GetValue() == x.GetValue();
	}
	int GetValue() const {return *mPtr;}
	void SetValue(int i) {*mPtr = i;}
private: 
	int* mPtr;
};

// Global function 
// We have to wrote both operand
//Integer operator+(const Integer& a, const Integer& b) 
//{
//	return Integer(a.GetValue() + b.GetValue());
//}
int main () 
{
	Integer a(1);
	Integer b(100);
	Integer c = a + b;
	cout<<c.GetValue()<<endl;
	c++;
	cout<<c.GetValue()<<endl;
	c = b;
	c=c;
	cout<< (c.GetValue() == b.GetValue()) <<endl;
	cout<<c.GetValue()<<endl;
}