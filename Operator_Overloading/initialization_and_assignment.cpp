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
		cout<<"Copy constructor called"<<endl;
		//cout<<"Copy ctor called"<<endl;
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
		cout<<"operator = is called"<<endl;
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
ostream& operator<<(std::ostream &out, const Integer &a)
{
	out<<a.GetValue();
	return out;
}


class IntPtr {
	Integer *m_p;
public: 
	IntPtr(Integer *p) : m_p(p) {}
	~IntPtr() {
		delete m_p;
	}

	Integer* operator->() {
		return m_p;
	}

	Integer& operator*() {
		return *m_p;
	}
};


class Product
{
private: 
	Integer m_Id;
public: 
	Product(Integer id):
	m_Id(std::move(id))
	{
		cout<<"Product created"<<endl;
		//m_Id = id;
	}
	~Product() 
	{
		cout<<"Product destructed"<<endl;
	}
};

int main () 
{
	//Integer a(5);

	//Integer b;
	//b = 5;

	Integer a(10);

	Product b(a);	
}