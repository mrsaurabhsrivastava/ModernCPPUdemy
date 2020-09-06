#include<iostream>
#include<experimental/filesystem>
using namespace std;
//using namespace std::experimental::filesystem;

namespace filesyste = std::experimental::filesystem;
int main () 
{
    filesyste::path lPath {R"(/home/ssrivast/work/cpp/udemy/CompleteModernCPP/file_io)"};
    //if (lPath.has_filename())
    //{
    //    std::cout<<lPath.filename()<<endl;
    //}

    for (const auto &x : lPath)
    {
        cout<<x<<endl;
    }

    filesyste::directory_iterator beg{lPath};
    filesyste::directory_iterator end{};
    if (beg != end)
    {
        cout<<*beg<<endl;
        ++beg;
    }
}
