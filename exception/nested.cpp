#include<iostream>
#include<limits>
#include<memory>
#include<vector>
#include<random>
using namespace std;

class Test 
{
    public: 
    Test() {cout<<__PRETTY_FUNCTION__<<endl;}
    ~Test() {cout<<__PRETTY_FUNCTION__<<endl;}
};

int ProcessRecords(unsigned long long count)
{
    if (count<10)
        throw std::out_of_range("No less than 10");
    std::vector<int> v;
    v.reserve(count);

    for (unsigned long long i = 0; i < count; i++)
    {
        v.push_back(i);
    }

    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    int lErroCount = 0;
    for (unsigned long long i = 0; i < count; i++)
    {
        try 
        {
            cout<<"Processing record # "<<i<<endl;
            if (!dist(eng))
            {
               ++lErroCount;
               throw std::runtime_error("Could not process record");   
            }
        }
        catch (std::runtime_error &ex)
        {
            std::cout<<"Error "<<ex.what()<<std::endl;
            if (lErroCount>4)
            {
              //  throw; // rethrow orignal object
                std::runtime_error err("Too many errors");
                ex = err;
                throw; // Now new execption will be thrown
            }
        }
    }
    return 0;
}
int main () 
{
    try {
        //ProcessRecords(std::numeric_limits<unsigned long long>::max());
        ProcessRecords(15);
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
    catch (std::exception &ex)
    {
        cout<<ex.what()<<endl;
    }
    /*
    catch (...)
    {
        cout<<"Exception"<<endl;
        // Does not give any info
    }
    */
}