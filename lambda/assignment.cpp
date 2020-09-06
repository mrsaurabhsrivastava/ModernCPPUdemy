#include<iostream>
#include<vector>
using namespace std;

int main () 
{
    auto largest = [] (auto x, auto y) {
        return x>y ? x : y;
    };

    auto greater = [] (auto x, auto y) {
        return x>y;
    };

    auto less = [] (auto x, auto y) {
        return x < y;
    };

    auto MinMax = [] (auto begin, auto end) {
        auto min = *begin;
        auto max = *begin;

        while(begin !=  end)
        {
            if (*begin < min)
                min = *begin;
            if (*begin > max)
                max = *begin;
            ++begin;        
        }
        return std::make_pair(min, max);
    };


    std::vector<int> vec{1,2,7,88,1,0};
    auto f = MinMax(vec.begin(), vec.end());
    cout<<f.first<<" "<<f.second<<endl;

}