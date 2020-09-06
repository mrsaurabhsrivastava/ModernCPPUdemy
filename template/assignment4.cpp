#include<iostream>
#include<string>

class c
{
    public: 
    c(std::string a, int b)
    {

    }
};

template <typename T, typename... Param> 
T * CreateObject(Param... args)
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
    return new T(std::forward<Param>(args)...);
}
int main () 
{
    int *p = CreateObject<int>(10);
    c *cptr = CreateObject<c, const char*, int>("Saurabh", 32);
}