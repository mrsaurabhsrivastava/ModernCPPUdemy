#include<iostream>

using namespace std;

class foo
{
private: 
	int mVar {0};
public:
	foo() = default;
	foo(int i)
	:mVar(i)
	{
	}

	void mSetInt(int i)
	{
		this->mVar = i;
	}
	void mSetInt(double) = delete;
	void mPrint() 
	{
		cout<<mVar<<endl;
	}
};

int main ( )
{
	foo f(0);
	f.mPrint();
	foo g;
	g.mSetInt(101);
	//g.mSetInt(101.9f);
	g.mPrint();

}