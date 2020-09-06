#include<iostream>

using namespace std;

int main () 
{
	int lVec[5] {10,1,13,9,15};
	for (auto v: lVec)
	{
		cout<<v<<" ";
		v=1;
	}
	cout<<endl;
	for (const auto v: lVec)
		cout<<v<<" ";
	cout<<endl;
	int *lVec1 = new int[10]; // std::begin and std::end not allowed on lVec1;
	int *lBeg = std::begin(lVec);
	int *lEnd = std::end(lVec);
	for (; lBeg != lEnd; lBeg++)
		cout<< *lBeg<<" ";
}

