#include<iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main () 
{
    fs::path selectedPath {R"(/home/ssrivast/work/cpp/udemy/CompleteModernCPP/c++17_feature)"};
    std::cout<<selectedPath.string()<<std::endl;
    fs::directory_iterator it(selectedPath);
    fs::directory_iterator end{};
    while (it != end)
    {
        auto dir = *it;
        std::cout<<dir.path().filename()<<std::endl;
        ++it;
    }
}