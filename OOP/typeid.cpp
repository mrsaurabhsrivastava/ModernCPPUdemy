#include<iostream>
#include<typeinfo>

using namespace std;

class A{
public:
    virtual void CallA(){} // Note if we remove virtual, type will not be ploymorphic
} ;
class B : public A{
} ;
int main(){
    B b ;
    A *a = &b ;
    const std::type_info &tin = typeid(*a);
    cout<<tin.name()<<endl; 
    std::cout << typeid(*a).name() << std::endl ;
    return 0 ;
}