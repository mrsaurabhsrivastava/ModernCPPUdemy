#include<iostream>
using namespace std;

int Add(int *a, int *b)
{
	return *a+*b;
}

void AddVal(int *a, int *b, int *result)
{
	*result = *a+*b;
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

}
void Factorial(int *a, int *result)
{
	*result = 1;
	for (int i = 1; i <= *a; i++)
		*result *= i;
}

int main () 
{
	int i = 3 , j = 5;
	cout<<Add(&i, &j)<<endl;
	int result;
	AddVal(&i, &j, &result);
	cout<<result<<endl;
	Swap(&i, &j);
	cout<<i<<" "<<j<<endl;

	Factorial(&i, &result);
	cout<<result<<endl;
}