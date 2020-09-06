#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>

class Employee
{
    private: 
    std::string dName;
    int         dId = -1;
    public: 
    Employee(std::string xName, int xId)
    :dName(std::move(xName)), 
     dId(std::move(xId))
     {

     }

    inline std::string mGetName() const {return dName;}
    inline int mGetId() const {return dId;}
};

class EmployeeHash
{
    public: 
    size_t operator() (const Employee &xEmp) const
    {
        auto s1 = std::hash<std::string>{} (xEmp.mGetName());
        auto s2 = std::hash<int>{} (xEmp.mGetId());
        return s1^s2;
    }
};

class EmployeeEquality
{
    public: 
    bool operator() (const Employee &xE1, const Employee &xE2) const
    {
        return xE1.mGetId() == xE2.mGetId() && 
               xE1.mGetName() == xE2.mGetName();
    }
};

std::ostream & operator<<(std::ostream &o, const Employee &x)
{
    o<<"Employee Name: "<<x.mGetName()<<" Id : "<<x.mGetId();
    return o;
}
int main () 
{

    /* auto my_hash = [](std::string const& foo) {
        return std::hash<std::string>()(foo);
    };

    auto hash = [] (const Employee& x) ->size_t {
        auto s1 = std::hash<std::string>{} (x.mGetName());
        auto s2 = std::hash<int>{} (x.mGetId());
        return s1^s2;
    };
    auto com = [] (const Employee &xE1, const Employee &xE2) ->bool {
        return xE1.mGetId() == xE2.mGetId() && 
               xE1.mGetName() == xE2.mGetName();
    };
    std::unordered_map<Employee, int, decltype(hash)> my_map(10, hash);
    std::unordered_set<Employee, decltype(hash), decltype(com)> lSet(10,hash, com); */
    // std::unordered_set<Employee, EmployeeHash, EmployeeEquality> lSet;
     auto hash = [] (const Employee& x) ->size_t {
        auto s1 = std::hash<std::string>{} (x.mGetName());
        auto s2 = std::hash<int>{} (x.mGetId());
        return s1^s2;
    };
    auto com = [] (const Employee &xE1, const Employee &xE2) ->bool {
        return xE1.mGetId() == xE2.mGetId() && 
               xE1.mGetName() == xE2.mGetName();
    };
    std::unordered_set<Employee, decltype(hash), decltype(com)> lSet(100,hash, com);

    std::unordered_set<Employee,
                       size_t (*)(const Employee&), 
                       bool (*)(const Employee& , const Employee&)> lSet1 (100,[] (const Employee& x) ->size_t
                                                                          {
                                                                                auto s1 = std::hash<std::string>{} (x.mGetName());
                                                                                auto s2 = std::hash<int>{} (x.mGetId());
                                                                                return s1^s2;
                                                                          }, 
                                                                          [] (const Employee &xE1, const Employee &xE2) ->bool
                                                                          {
                                                                                    return xE1.mGetId() == xE2.mGetId() && 
                                                                                    xE1.mGetName() == xE2.mGetName();

                                                                          }); 
    // lSet.insert(Employee("Saurabh", 13761));
    // lSet.insert(Employee("Graura", 12344));
    // for (const auto &x:lSet)
    //     std::cout<<x<<std::endl;
}