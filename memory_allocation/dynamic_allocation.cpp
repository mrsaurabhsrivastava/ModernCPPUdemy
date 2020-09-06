#include<stdio.h>
#include<stdlib.h>

int main () 
{
	int *p = (int*)malloc(sizeof(int));
	//int *p = (int*)calloc(1,sizeof(int)); calloc only initialize memory to 0, no other value
	// always check return ptr is NULL 
	// if it fail to allocate memory, it will return NULL
	printf("%d\n", *p);
	*p =5;
	printf("%d\n", *p);
	free(p);
	p = NULL;

	// array allocation 
	int *arr = (int*)malloc(5*sizeof(int));
	int *arr1 = (int*)calloc(5, sizeof(int));
}