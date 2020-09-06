#include<iostream>
using namespace std;


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
		cout<<"Move = operator caaled"<<endl;
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

	void operator() ()
	{
		cout<<GetValue()<<endl;
	}
	int GetValue() const {return *mPtr;}
	void SetValue(int i) {*mPtr = i;}
private: 
	int* mPtr;
};


Integer operator+(int a , const Integer& b)
{
	return Integer(a+b.GetValue());
}

ostream& operator<<(std::ostream &out, const Integer &a)
{
	out<<a.GetValue();
	return out;
}

istream& operator>>(std::istream &in, Integer &a)
{
	int lInput;
	in>>lInput;
	a.SetValue(lInput);
	return in;
}

int main () 
{
	Integer a{1};
	Integer sum = a+4; //a.operator+(5);
	Integer sum1 = 5+a; // this will not work , should overload it as global function
	cout<<sum1<<endl; // -> operator<<(std::cout, sum1) -> it returns a ostream obj
	/*->*/ operator<<(cout, sum1).operator<<(endl);

	//cin>>a;
	//cout<<a<<endl;
	a();
}