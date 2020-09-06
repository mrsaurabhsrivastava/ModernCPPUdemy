#include <iostream>
using namespace std;

namespace mynamespace 
{
	class foo
	{
	public: 
		foo(); 
		~foo() = default;
	};

	namespace nested
	{
		class ff
		{
		public: 
			ff();
			~ff() = default;
		};


	};
};

// One way
/*
mynamespace::foo::foo() 
{
	cout<<"foo created"<<endl;
}
mynamespace::nested::ff::ff() 
{
	cout<<"ff created"<<endl;
}
*/
// another way
/*
namespace mynamespace 
{
	foo::foo() 
	{
		cout<<"foo created"<<endl;
	}
	namespace nested
	{
		ff::ff() 
		{
			cout<<"ff created"<<endl;	
		}
	}
}
*/
// More Another way
using namespace mynamespace;
foo::foo() 
{
		cout<<"foo created"<<endl;
}
using namespace nested;
ff::ff() 
{
	cout<<"ff created"<<endl;	
}

// unnamed namespace 
// will be visible only in this file. Like static variable?
namespace {
	void internal() 
	{
		cout<<"internal called"<<endl;
	}
}
int main () 
{
	mynamespace::foo f;
	mynamespace::nested::ff ok;
	internal();
}