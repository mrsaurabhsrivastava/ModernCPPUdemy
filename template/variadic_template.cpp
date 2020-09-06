#include<iostream>
#include "Integer.h"

//template <typename T>
//void Print(std::initializer_list<T> args) // all argument should be same type
//{
//    for(const auto &x : args)
//        std::cout<<x<<" ";
//}
//base case function
void Print()
{
    std::cout<<std::endl;
}
// template parameter pack
// it is alias to the list of typename
template<typename T, typename...Params>
// Function parameter pack
void Print(T a, Params&&... args)
{
    //std::cout<<sizeof...(args)<<" "<<sizeof...(Params)<<std::endl;
    std::cout<<a<<" ";
    // we have to do recursion 
    // one argument will decrease by 1 in each recurstion 
    // we have to write base function 
    Print(std::forward<Params>(args)...);
}

std::ostream & operator<<(std::ostream &o, const Integer &obj)
{
    o<<obj.mGetValue();
    return o;
}
int main () 
{
    Integer val(1);
    Print(0, Integer(2), val);
    //Print(1,2,3,"4");
    //Print("S",1);
}