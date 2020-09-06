#include<iostream>

#ifdef __has_include
#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else 
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif
#endif

int main ()
{
#ifdef __has_include
#if __has_include(<filesystem>)
#include <filesystem>
std::cout<<"I am here"::std::endl;
namespace fs = std::filesystem;
#else 
#include <experimental/filesystem>
std::cout<<"I am here11"<<std::endl;
namespace fs = std::experimental::filesystem;
#endif
#endif
}