#include<iostream>
#include<memory>
using namespace std;


class Printer
{
	weak_ptr<int> mId;
public: 
	void SetValue(shared_ptr<int> xId)
	{
		mId=xId;
	}
	void mPrint() 
	{
		cout<<mId.use_count()<<endl;
		if (!mId.expired())
		{
			cout<<*(mId.lock())<<endl;
		}
		else 
		{
			cout<<"Pointer is expired"<<endl;
		}
		//cout<<mId.lock()<<endl;
		//cout<<*(mId.lock())<<endl;
	}
};


int main () 
{
	Printer prn;
	shared_ptr<int> p = std::make_shared<int>(101);
	prn.SetValue(p);
	prn.mPrint();

	if (*p>10)
	{
		p = nullptr;
		cout<<"i am here"<<endl;
	}	

	prn.mPrint();
}