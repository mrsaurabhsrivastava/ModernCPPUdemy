#include<iostream>
#include<memory>
#include<functional>

int main () 
{
    std::unique_ptr<int> lPtr = std::make_unique<int>(10);

    auto lambda = [lPtr = std::move(lPtr)] () {
        std::cout<<*lPtr<<std::endl;
    };

    lambda();

    auto mylambda = std::move(lambda);
    // std::function<void()> fun = std::move(mylambda);
    /*std::function<void()> fun = [ obj = std::make_shared<decltype(mylambda)>(std::move(mylambda)) ] () 
    {
        (*obj)();
    };
    */
    auto obj1 = new decltype(mylambda)(std::move(mylambda));
    (*obj1)();
    std::cout<<typeid(obj1).name()<<std::endl;
}