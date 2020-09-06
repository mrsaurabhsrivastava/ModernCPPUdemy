#include <iostream>
#include <string>
#include "Integer.h"

#define __DEBUG__

class Employee 
{
    std::string  mName;
    Integer mId;
    public: 
    /*Employee(const std::string &xName, const Integer &xId)
    :mName(xName),
     mId(xId)
     {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
     }
     

     Employee(std::string &&xName, Integer &&xId)
     :mName(std::move(xName)), 
      mId(std::move(xId))
     {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif

     }
     */
    template<typename T1, typename T2>
    Employee(T1 &&xName, T2 &&xId)
    :mName{std::forward<T1>(xName)}, 
     mId{std::forward<T2>(xId)}
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif

    } 
};

template <typename T1, typename T2>
Employee CreateEmp(T1 &&a, T2 &&b)
{
    return new Employee{std::forward<T1>(a),std::forward<T2>(b)};
}
int main () 
{
    //Employee e("Saurabh", Integer{13761});
    Integer I(17361);
    Employee e("Saurabh", I);
    //std::string lName {"Srivastava"};
    //Employee e1 {lName, 12344};
    //std::cout<<"I am done"<<std::endl;

    std::string s = "saurabh"; 
    s+s = s;
    std::cout<<s<<std::endl;

}