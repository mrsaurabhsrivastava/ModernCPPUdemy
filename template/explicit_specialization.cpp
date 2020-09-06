#include<iostream>
#include<cstring>

template<typename T>
T Max (T x, T y)
{
    std::cout<<typeid(T).name()<<std::endl;
    return x>y ? x : y;
}

template char Max(char x, char y);

// Explicit instantiation is alreay instantiated, 
// This should be written in cpp file otherwise we will 
// get multiple defination error 
template <> const char* Max<const char*> (const char *x, const char *y)
{
    std::cout<<"Explicit specialization work "<<std::endl;
    return strcmp(x,y) > 0? x : y;
}


int main () 
{
   const char *a{"A"};
   const char *b{"B"};
   auto s = Max(a,b);
   std::cout<<s<<std::endl; // wrong, will compare address not address value

}