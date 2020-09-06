#include<iostream>


class foo
{
    // template<char... _Digits>
    public: 
    foo(unsigned long long i)
    {

    }
};
    
auto operator""ms(unsigned long long i)
{
        return foo(i);
}

int main () 
{
    foo f = 1ms;
}