#include<iostream>
using namespace std;

union Test
{
	int x;
	char c;
	Test() 
	:x(1)
	 //c('0') only one member initialization is allowed

	{
		//cout<<__FUNCTION__<<endl;
		cout<<__PRETTY_FUNCTION__<<endl;
	}
	~Test() 
	{

	}
};
int main ()
{
	Test g;
}