#include<iostream>
#include<string>
#include<initializer_list>
#include<cassert>
using namespace std;

class Bag
{
	int m_arr[10];
	int m_size{0};
public: 
	Bag(std::initializer_list<int> xList)
	{
		assert(xList.size() < 10);
		auto it = xList.begin();
		while(it != xList.end())
		{
			Add(*it);
			++it;
		}	
	}
	void Add(int xValue)
	{
		assert(m_size < 10);
		m_arr[m_size++] = xValue;
	}

	void Remove() 
	{
		--m_size;
	}

	int operator[](int xIndex) const {
		return m_arr[xIndex];
	}
	int GetSize() const 
	{
		return m_size;
	}
};

void Print(std::initializer_list<int> xList)
{
	auto it = xList.begin();
	while(it != xList.end())
	{
		cout<<*it++ <<" ";
	}
}

int main () 
{
	int x{0};
	float y(0.9f);
	int arr[5]{3,4,1,2,3};
	string s{"Saurabh c++"};
	std::initializer_list<int> data = {1,2,3,4};
	auto values = {1,2,3,4};

	Bag b {1,2,3,4};
	b.Add(4);
	b.Add(6);

	for (int i = 0; i < b.GetSize() ; ++i)
	{
		cout<<b[i]<<" ";
	}

	Print({1,3,4,5});

	cout<<endl;
	for (auto v:{3444,4,4,2})
		cout<<v<<endl;
}