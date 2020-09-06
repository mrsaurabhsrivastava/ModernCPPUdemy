#include<iostream>

inline int i = 0;

class Test
{
    public:
    inline static int j  =109;
};
int main () 
{
    std::cout<<Test::j;
}