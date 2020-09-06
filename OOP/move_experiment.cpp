#include <iostream>
#include <string>
#include <benchmark/benchmark.h>

using namespace std;
class StringMove
{
public: 
	StringMove(std::string x) 
	:s(std::move(x))
	{

	}

	StringMove(const StringMove& obj)
	{
		//cout<<"Copy Constructor called"<<endl;
		s = obj.s;
	}

	StringMove(StringMove&& obj)
	{
		//cout<<"Move Constructor called"<<endl;
		s = std::move(obj.s);
	}
private:
	std::string s; 
};

class fooMove
{
public: 
	fooMove(StringMove x): dMyStr(std::move(x))
	{

	}
	
private: 
	StringMove dMyStr;
};

class StringRef
{
public: 
	StringRef(std::string x) 
	:s(std::move(x))
	{

	}

	StringRef(const StringRef& obj)
	{
		//cout<<"Copy Constructor called"<<endl;
		s = obj.s;
	}

	StringRef(StringRef&& obj)
	{
		//cout<<"Move Constructor called"<<endl;
		s = std::move(obj.s);
	}
private:
	std::string s; 
};

class fooRef
{
public: 
	fooRef(StringRef& x) : dMyStr(x)
	{

	}
private: 
	StringRef dMyStr;
};


static void gCreateObjWithMove(benchmark::State &state)
{
	while(state.KeepRunning())
	{
		StringMove S("Saurabh");
		for(int i = 0; i < 100000; i++)
		{
			fooMove *f = new fooMove(S);
		}
	}
}
static void gCreateObjWithRef(benchmark::State &state)
{
	while(state.KeepRunning())
	{
		StringRef S("Saurabh");
		for(int i = 0; i < 100000; i++)
		{
			fooRef *f = new fooRef(S);
		}
	}
}
BENCHMARK(gCreateObjWithMove);
BENCHMARK(gCreateObjWithRef);
BENCHMARK_MAIN();
