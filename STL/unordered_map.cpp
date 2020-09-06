#include<iostream>
#include<string>
#include<unordered_map>

int main () 
{
    std::unordered_map<int, std::string> lMap;
    lMap.insert(std::make_pair(1,"Saurabh")) ;
    lMap.insert(std::make_pair(2,"Gaurav"));
    for (const auto &v : lMap)
    {
        std::cout<<lMap.bucket(v.first)<<std::endl;
    }
    std::cout<<lMap.bucket_count()<<std::endl;
    std::cout<<lMap.load_factor()<<std::endl;
    std::cout<<lMap.max_load_factor()<<std::endl;
    std::cout<<lMap.max_bucket_count()<<std::endl;
}