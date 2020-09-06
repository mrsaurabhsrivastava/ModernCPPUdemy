#include<iostream>
using namespace std;


class foo
{
private: 
	int* mPtr = nullptr;
public: 
	foo() 
	:foo(0)
	{
		
	}
	foo(int i)
	{
		mPtr = new int(i);
	}
	foo(const foo& obj)
	{
		
		mPtr = new int(*obj.mPtr);
	}
	~foo() 
	{
		delete mPtr;
	}
	int mGetInt() const 
	{
		return *mPtr;
	}

	void mSetInt(int i) {*mPtr = i;}
};
int main () 
{
	foo i(10);
	cout<<i.mGetInt()<<endl;
	foo j(i);
	cout<<j.mGetInt()<<endl;
	i.mSetInt(13);
	cout<<j.mGetInt()<<endl;
}