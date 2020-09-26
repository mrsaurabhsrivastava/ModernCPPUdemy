#include<iostream>
#include<string_view>

using namespace std::string_view_literals;
int main () 
{
    std::string_view sv1 = "Hello World";
    std::string str1 {"Hello"};
    std::string_view sv2 = str1;

    auto sv3 = "Using \0literals"sv;

    std::cout<<"Size "<<sv3.length()<<std::endl;
    std::cout<<sv3<<std::endl;
    std::cout<<"data() "<<sv3.data()<<std::endl;

    std::cout<<sv2<<std::endl;
    str1 = "Check";
    std::cout<<sv2<<std::endl;
}