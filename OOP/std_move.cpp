#include<iostream>
using namespace std;
// std::move always work on lavalue
// force compiler to use move ctor
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

void Print(Integer val)
{
	cout<<val.GetValue()<<endl;
}
int main ()
{
	Integer a(1);
	//auto b(a); // it will call copy controctor 
	// suppose i don't want to use a After b 
	// so i can move a to b 
	// by forcing move constructor 
	// I am creating c by converting a to rlvalue reference
	//->auto c(static_cast<Integer&&>(a));
	// above code is not readable 
	// use std::move it, internally perform same case 
	// auto d (std::move(a));
	//Print(std::move(a)); // it ill move a to tmp variale val
	// Print(static_cast<Integer&&> (a)); //<- same thin
	// val will automatically deleted after finishing Print 
	// function, a is not usable after this call
	//cout<<a.GetValue()<<endl;
}