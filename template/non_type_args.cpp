#include<iostream>
#include<cstring>

template<typename T>
T Max (T x, T y)
{
    std::cout<<typeid(T).name()<<std::endl;
    return x>y ? x : y;
}

template char Max(char x, char y);

// Explicit instantiation is alreay instantiated, 
// This should be written in cpp file otherwise we will 
// get multiple defination error 
template <> const char* Max<const char*> (const char *x, const char *y)
{
    std::cout<<"Explicit specialization work "<<std::endl;
    return strcmp(x,y) > 0? x : y;
}


template<int size>
void Print() 
{
    char buf[size];
    std::cout<<"Size "<<size<<std::endl;
}

/*
template <typename T>
T Sum(T *parr, int size)
{
    T sum{};
    for (int i = 0; i < size; i++)
        sum += parr[i];
    return sum;

}
*/

template <typename T, int size>
T Sum(T (&parr)[size])
{
    T sum{};
    for (int i = 0; i < size; i++)
        sum += parr[i];
    return sum;

}
int main () 
{
    //constexpr int i = 2;
    //Print<i>();

    int arr[] {1,2,3,4,5,6};
    //int sum = Sum(arr, 6);
    //std::cout<<sum<<std::endl;

    int (&ref) [6] = arr;
    int sum = Sum(arr);
    std::cout<<sum<<std::endl;

    auto it = std::begin(arr);

}