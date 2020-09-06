#include<iostream>
#include<memory>
using namespace std;


class Printer
{
	shared_ptr<int> mId;
public: 
	void SetValue(shared_ptr<int> xId)
	{
		mId=xId;
	}
	void mPrint() 
	{
		cout<<mId.use_count()<<endl;
		cout<<*mId<<endl;
	}
};

void intDelete(int *x) 
{
	cout<<"deleter called"<<endl;
	cout<<*x<<endl;
}


int main () 
{
	Printer prn;
	shared_ptr<int> p = std::make_shared<int>(101);
	prn.SetValue(p);
	prn.mPrint();
	unique_ptr<int, void(*)(int*)> p1(new int(1001), intDelete);

		unique_ptr<std::FILE, void(*)(std::FILE*)> fp(std::fopen("abc.txt","w"), [] (std::FILE* fp) {std::fclose(fp);} );
        unique_ptr<std::FILE, void(*)(std::FILE*)> fp3(std::fopen("abc.txt","w"), [] (std::FILE* fp) {std::fclose(fp);} );
	if (*p>10)
	{
		p1 = nullptr;
		cout<<"i am here"<<endl;
	}	

	prn.mPrint();
}