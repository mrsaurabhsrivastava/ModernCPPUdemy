#include<iostream>
#include<fstream>
#include<string>
#include<experimental/filesystem>

namespace filesystem = std::experimental::filesystem;

bool CopyBinaryFile(const filesystem::path &xSource, const filesystem::path &xDest, std::string &Error)
{
    std::ifstream in;
    std::ofstream out;
    bool lStatus = false;
    in.open(xSource, std::ios::binary);

    if(!in.is_open())
    {
        Error = "Could not open source file.\n";
        return lStatus;
    }

    if (filesystem::exists(xDest))
    {
        Error = "Destination file already exists.\n";
        return lStatus;
    }
    out.open(xDest,std::ios::binary);
    if (!out.is_open())
    {
        Error = "Could not open destination file.\n";
        return lStatus;
    }

    lStatus = true;
    in.seekg(0,std::ios::end);
    auto size = in.tellg();
    std::cout<<size<<std::endl;
    in.clear();
    in.seekg(0);
    std::string lData(size, '\0');
    in.read(&lData[0], size);
    out.write(&lData[0],size);
    return lStatus;
}

int main (int argc, const char* argv[]) 
{
    if (argc < 3)
    {
        std::cout<<"Invalid usage "<<std::endl;
        return -1;
    }
    std::string lSourceFile(argv[1]);
    std::string lDestFile(argv[2]);

    filesystem::path lSource {lSourceFile};
    filesystem::path lDest {lDestFile};
    std::string lError;
    if (!CopyBinaryFile(lSourceFile, lDestFile, lError))
    {
        std::cout<<lError;
        return -1;
    }
    return 0;
}