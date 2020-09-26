#include<iostream>
#include<optional>

std::optional<const char*> getMsg(int errnom)
{
    const char *s = nullptr;
    switch (errnom)
    {
    case 1:
        s = "My error message";
        break;
    case 2:
        s = "My 2 message";
        break;
    default: 
        s = "";
    }
    return std::nullopt;
}

int main () 
{
    std::optional s = getMsg(1);
    if (s.has_value())
    {
        std::cout<<s.value()<<std::endl;
    }
    else 
    {
        std::cout<<"No value "<<std::endl;
    }
    std::cout<<sizeof(s)<<std::endl;
    auto l = [] () {};
    std::cout<<sizeof(l)<<std::endl;
}