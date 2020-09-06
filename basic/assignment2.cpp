#include<iostream>
using namespace std;
int main () 
{
	int x = 5;
	const int MAX = 12;
	int &ref_x = x;
	const int &const_ref_x = x;
	ref_x = 11;
	//const_ref_x = 14; not allowed

	const int *ptr1 = &x; // pointer to const int ,*ptr is const but ptr is not
	int *const ptr2 = &x; // const pointer to int, ptr is const but *ptr is not
	const int * const ptr3 = &x; // const pointer to const int, *ptr and ptr both const

	const int *ptr4 = &MAX;
	//int *ptr5 =  &MAX; // will not allowed 

	const int &r1 = ref_x;
	//int &r2 = const_ref_x;// problem 
	const int *&p_ref1 = ptr1;
	cout<<*p_ref1<<endl;

	const int* ptr5 = &MAX;
	const int *&p_ref2 = ptr5;



}