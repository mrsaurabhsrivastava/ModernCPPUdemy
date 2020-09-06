#include<iostream>
#include<string>
#include<type_traits>

template <typename T>
void fun(T &&x) 
{
    x = "Check";
    std::cout<<std::boolalpha;
    std::cout<<"Is T rvalue reference = "<<std::is_rvalue_reference_v<T&&><<std::endl;
}
int main () 
{
    std::string s{"C++"};
    fun(s);
    std::cout<<"String value = "<<s<<std::endl;
    std::cout<<s.size()<<std::endl;
}