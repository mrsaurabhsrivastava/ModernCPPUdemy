#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Product
{
    private: 
    std::string dName;
    double dPrice = 0;
    public: 
    Product(const std::string &xName, double xPrice)
    : dName(xName), 
      dPrice(xPrice)
    {

    }

    operator double() const {return dPrice;}
    void ReAssignPrice(const std::vector<double>& xTaxes) 
    {
        double basePrice = dPrice;
        for_each(xTaxes.begin(), xTaxes.end(), 
                 [basePrice, pr = this] (const double &d) mutable {
                    pr->dPrice += ((basePrice * d) / 100); 
                 }); 
    }

    double GetPrice() const {return dPrice;}
};

int main () 
{
    atexit([] () {std::cout<<"I am exiting, Good Bye..."<<std::endl;});
    std::vector<double> lTaxes {3,4,5};
    Product P("Product", 100);
    P.ReAssignPrice(lTaxes);
    std::cout<<P.GetPrice()<<std::endl;

    double m = static_cast<double>(P);
    std::cout<<m<<std::endl;

}