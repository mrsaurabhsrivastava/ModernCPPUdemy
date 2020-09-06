#include<iostream>
using namespace std;
class Integer
{
	friend ostream& operator<<(ostream &out, const Integer& a);

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

ostream& operator<<(std::ostream &out, const Integer &a)
{
	out<<*a.mPtr<<endl;;
	return out;
}

class Printer
{

};

int main () 
{
	Integer a(101);
	cout<<a<<endl;
}