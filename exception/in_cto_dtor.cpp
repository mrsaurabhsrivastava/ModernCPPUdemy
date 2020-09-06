#include<iostream>
using namespace std;

void Test (int x) 
{
    cout<<x<<endl;
    throw 5;
}

int Sum(int x , int y)  noexcept(noexcept(Test(x)))
{
    Test(x);
    return x+y;
}

int main () 
{
    int x = 0;
    cout<<std::boolalpha<<noexcept(Test(x))<<endl;
    try
    {
        Sum(19,11);
    }
    catch(std::exception &ex)
    {
        cout<<"Exceptrion cought"<<endl;
    }
    catch (int i)
    {
        cout<<"mmm"<<endl;
    }
    catch(...)
    {
        cout<<"I am here"<<endl;
    }
}