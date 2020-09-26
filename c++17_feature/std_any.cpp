#include<iostream>
#include<string>
#include<any>


using namespace std::string_literals;
int main () 
{
    std::any v1 = 5;
    //v1 = "Hello"s;
  /*   try{
        std::cout<<std::any_cast<std::string>(v1)<<std::endl;
    } catch (std::exception &ex)
    {
        std::cout<<"Exception: "<<ex.what()<<std::endl;
    } */
    
  
    // if (v1.has_value())
    // {

    // }

    auto &f = std::any_cast<int&> (v1);
    std::cout<<typeid(f).name()<<std::endl;
    f = 6;
    std::cout<<std::any_cast<int>(v1)<<std::endl;
    v1.reset();

}