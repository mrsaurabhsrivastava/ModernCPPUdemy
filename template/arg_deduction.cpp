#include<iostream>

template<typename T>
T Max (T x, T y)
{
    std::cout<<typeid(T).name()<<std::endl;
    return x>y ? x : y;
}

template char Max(char x, char y);

int main () 
{
    Max<double>(3,5.1f);
    Max(3.1, 6.2);

    int (*pFn)(int, int) = Max;
}