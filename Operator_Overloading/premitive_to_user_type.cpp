#include<iostream>
#include<memory>
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
		cout<<"Assignment operator called"<<endl;
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

	// type conversion operator 
	explicit operator int () const {return GetValue();}
	int GetValue() const {return *mPtr;}
	void SetValue(int i) {*mPtr = i;}
private: 
	int* mPtr;
};

void Print(const Integer& a)
{
	cout<<a.GetValue()<<endl;
}
int main () 
{
	//Integer a1(4);

	int c = static_cast<int>(Integer(1));
	cout<<c <<endl;

	//Integer a2 = 5.6;
	//Print(4.5);
	//a1 = 10;
	//a1 = 8;
	//Print(a1);
}