#include<iostream>
#include<limits>
#include<memory>
using namespace std;

class Test 
{
    public: 
    Test() {cout<<__PRETTY_FUNCTION__<<endl;}
    ~Test() {cout<<__PRETTY_FUNCTION__<<endl;}
};

int ProcessRecords(unsigned long long count)
{
    //Test t;
    //Test *p = new Test();
    std::unique_ptr<Test> p =  std::make_unique<Test>();
    if (count<10)
        throw std::out_of_range("Should be > 10");
    //int *pArray = (int*)malloc(count * sizeof(int));
    int *pArray = new int [count];
    if (pArray == nullptr)
    {
        throw std::runtime_error("Failed to allocate memory");
        //cout<<"Failed to allocate memory"<<endl;
        //return -1;
    }
    cout<<pArray<<endl;
    //delete p;
    return 0;
}
int main () 
{
    try {
        ProcessRecords(std::numeric_limits<unsigned long long>::max());
        //ProcessRecords(5);
    } 
    /*catch (std::runtime_error &ex)
    {
        std::cout<<ex.what()<<endl;
    }
    catch (std::out_of_range &ex)
    {
        std::cout<<ex.what()<<endl;
    }
    catch (std::bad_alloc &ex)
    {
        cout<<ex.what()<<endl;
    }*/
    /*catch (std::exception &ex)
    {
        cout<<ex.what()<<endl;
    }*/
    catch (...)
    {
        cout<<"Exception"<<endl;
        // Does not give any info
    }
}