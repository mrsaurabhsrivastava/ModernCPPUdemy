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
Integer* GetPointer(int xValue)
{
	return new Integer(xValue);
}

void Store(std::unique_ptr<Integer> p)
{
	cout<<"Storing data info a file"<<p->GetValue()<<std::endl;
}

void Display(Integer *p)
{
	if (!p)
		return;
	cout<<p->GetValue()<<endl;
}
void Operate(int xValue)
{
	std::unique_ptr<Integer> p (GetPointer(xValue));
	if (p == nullptr)
	{
		// old pointer will be deleted and take ownership 
		// of new pointer
		p.reset(new Integer(xValue));
	}

	p->SetValue(1001);
	Display(p.get());
	p = nullptr;
	p.reset(new Integer(__LINE__));
	Display(p.get());

	Store(std::move(p));

	// after this do not use p pointer 
	// without reseting it
	// We can pass it by reference
}
int main ()
{
	Operate(5);
}