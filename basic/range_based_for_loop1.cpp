#include<iostream>
using namespace std;

int main () 
{
	int arr[] = {1,2,3,4,5};

	int *beg = &arr[0];
	int *end = &arr[5]; // location just after array

	auto &&range = arr;
	// new way to write above lines 
	int *newBeg = std::begin(arr);
	int *newEnd = std::end(arr);

	cout<<beg<<" "<<end<<" "<<newBeg<<" "<<newEnd<<endl;
	while(beg != end)
	{
		cout<<*beg<<" ";
		++beg;
	}

	cout<<endl;
	// range based for loop
	for (;newBeg != newEnd; ++newBeg)
	{
		auto v = *newBeg;
		cout<<v<<'-';
	}

	// in c++17 newBeg and newEnd should be same type
	// that is not in the case of char array

}