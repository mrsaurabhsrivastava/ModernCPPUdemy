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

void Process(std::unique_ptr<Integer> ptr)
{
	cout<<ptr->GetValue()<<endl;
	// here ptr will be destroyed and underline memory will
	// be deleted
}
void CreateInteger() 
{
	std::unique_ptr<Integer> ptr(new Integer);
	//auto p2(std::move(ptr));
	ptr->SetValue(10);
	cout<<ptr->GetValue()<<endl;	
	Process(std::move(ptr));
}

void ProcessShared(std::shared_ptr<Integer> p) 
{
	cout<<p->GetValue()<<endl;
	p->SetValue(1010);
	cout<<p.use_count()<<endl;
}

void CreateSharedInteger() 
{
	std::shared_ptr<Integer> ptr = std::make_shared<Integer>();
	//auto p2(std::move(ptr));
	ptr->SetValue(10);
	cout<<ptr->GetValue()<<endl;	
	ProcessShared(ptr);
	cout<<ptr->GetValue()<<endl;
}
int main () 
{
	CreateInteger();
	CreateSharedInteger();
}