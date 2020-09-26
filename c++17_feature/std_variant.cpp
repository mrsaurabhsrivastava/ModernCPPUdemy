#include<iostream>
#include<variant>
#include<string>


int main () 
{
    std::variant<std::string, int, char> v{5};
    auto val = std::get<int> (v);
    std::cout<<val<<std::endl;
    auto val1 = std::get<1>(v);
    std::cout<<val1<<std::endl;
    auto activeIndex = v.index();

    auto p = std::get_if<std::string> (&v);
    std::cout<<p<<std::endl;
}