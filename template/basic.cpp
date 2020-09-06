#include<iostream>

template <typename T> 
T Max(T x, T y)
{
    return x>y ? x : y;
}

int main () 
{
    auto num = Max(3.5f, 3.6f);
    std::cout<<num<<std::endl;
    decltype(num) x;
    auto num2 = Max(3, 7);
    std::cout<<num2;
    
}