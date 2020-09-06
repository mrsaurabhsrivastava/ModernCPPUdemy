#include<iostream>
#include<typeinfo>
#include<functional>


void gFun(int(*fn)(int, int))
{

}
int main() 
{
    auto fun = [] () {std::cout<<"I am lambda\n";
    std::cout<<__PRETTY_FUNCTION__<<std::endl;};
    fun();
    std::cout<<typeid(fun).name()<<std::endl;

    auto sum = [] (int x , int y) 
    {
        return x+y;
    };

    std::cout<<sum(9,3)<<std::endl;

    int (*fn) (int, int) = sum;
    //fn = sum;
    //std::function<void(int,int)> f = sum;
    //gFun(sum);
    std::cout<<fn(10,2)<<std::endl;
    gFun(sum);
}