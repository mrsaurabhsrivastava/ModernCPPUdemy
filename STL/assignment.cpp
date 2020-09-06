#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//#define __DEBUG__
class ContactManager;
class Contact
{
    friend class ContactManager;

public:
    enum class Group
    {
        FRIENDS,
        COWROKER,
        ACQUAINTANCE,
        FAMILY,
        UNASSIGNED
    };

    Contact(const std::string &xFirstName,
            const std::string &xLastName,
            uint64_t xPrimaryContactNumber,
            uint64_t xSecondaryContactNumber,
            const std::string &xEmailId,
            const std::string &xAddress,
            const std::string &xCompany,
            Contact::Group xGroup)
        : dFirstName(xFirstName),
          dLastName(xLastName),
          dPrimaryContactNumber(xPrimaryContactNumber),
          dSecondaryContactNumber(xSecondaryContactNumber),
          dEmailId(xEmailId),
          dAddress(xAddress),
          dCompany(xCompany),
          dGroup(xGroup)
    {
#ifdef __DEBUG__
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    }
    Contact(const Contact &obj)
    {

#ifdef __DEBUG__
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        dFirstName = obj.dFirstName;
        dLastName = obj.dLastName;
        dPrimaryContactNumber = obj.dPrimaryContactNumber;
        dSecondaryContactNumber = obj.dSecondaryContactNumber;
        dEmailId = obj.dEmailId;
        dAddress = obj.dAddress;
        dCompany = obj.dCompany;
        dGroup = obj.dGroup;
    }

    Contact(Contact &&obj)
    {
#ifdef __DEBUG__
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        dFirstName = obj.dFirstName;
        dLastName = obj.dLastName;
        dPrimaryContactNumber = obj.dPrimaryContactNumber;
        dSecondaryContactNumber = obj.dSecondaryContactNumber;
        dEmailId = obj.dEmailId;
        dAddress = obj.dAddress;
        dCompany = obj.dCompany;
        dGroup = obj.dGroup;
    }

    Contact &operator=(const Contact &obj)
    {
#ifdef __DEBUG__
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        dFirstName = obj.dFirstName;
        dLastName = obj.dLastName;
        dPrimaryContactNumber = obj.dPrimaryContactNumber;
        dSecondaryContactNumber = obj.dSecondaryContactNumber;
        dEmailId = obj.dEmailId;
        dAddress = obj.dAddress;
        dCompany = obj.dCompany;
        dGroup = obj.dGroup;
        return *this;
    }

    Contact &operator=(Contact &&obj)
    {
#ifdef __DEBUG__
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        dFirstName = obj.dFirstName;
        dLastName = obj.dLastName;
        dPrimaryContactNumber = obj.dPrimaryContactNumber;
        dSecondaryContactNumber = obj.dSecondaryContactNumber;
        dEmailId = obj.dEmailId;
        dAddress = obj.dAddress;
        dCompany = obj.dCompany;
        dGroup = obj.dGroup;
        return *this;
    }
    void mPrint() const 
    {
        std::cout<<"Name : "<<dFirstName<<" "<<dLastName<<std::endl;
        std::cout<<"Contact : "<<dPrimaryContactNumber<<" "<<dSecondaryContactNumber<<std::endl;
        std::cout<<"Email : "<<dEmailId<<std::endl;
        std::cout<<"Address :"<<dAddress<<std::endl;
        std::cout<<"Company :"<<dCompany<<std::endl;
        std::cout<<"Group : "<<static_cast<int>(dGroup)<<std::endl;
    }

private:
    std::string dFirstName;
    std::string dLastName;
    uint64_t dPrimaryContactNumber;
    uint64_t dSecondaryContactNumber;
    std::string dEmailId;
    std::string dAddress;
    std::string dCompany;
    Group dGroup = Group::UNASSIGNED;
};

class ContactManager
{
public:
    void mAddContact(const std::string &xFirstName,
                     const std::string &xLastName,
                     uint64_t xPrimaryContactNumber,
                     uint64_t xSecondaryContactNumber,
                     const std::string &xEmailId,
                     const std::string &xAddress,
                     const std::string &xCompany,
                     Contact::Group xGroup)
    {
        dContactList.emplace_back(xFirstName,
                                  xLastName,
                                  xPrimaryContactNumber,
                                  xSecondaryContactNumber,
                                  xEmailId,
                                  xAddress,
                                  xCompany,
                                  xGroup);
    }

    void mPrintShortedFirstName()
    {
        std::sort(dContactList.begin(), dContactList.end(), [](const Contact &x1, const Contact &x2) { return x1.dFirstName < x2.dFirstName; });
        for (const auto &v : dContactList)
        {
            v.mPrint();
        }
    }
    void mPrintShortedLastName()
    {
        std::sort(dContactList.begin(), dContactList.end(), [](const Contact &x1, const Contact &x2) { return x1.dLastName < x2.dLastName; });
        for (const auto &v : dContactList)
        {
            v.mPrint();
        }
    }

private:
    std::vector<Contact> dContactList;
};

int main()
{
    ContactManager lContactManager;
    lContactManager.mAddContact("Saurabh",
                                "Srivastava",
                                9971348199,
                                9540048530,
                                "mr.saurabh.srivastava@gmail.com",
                                "Noida",
                                "Mentor Graphics",
                                Contact::Group::FAMILY);

    lContactManager.mAddContact("Suhasini",
                                "Srivastava",
                                9540048530,
                                9971348199,
                                "shinii.sri@gmail.com",
                                "Noida",
                                "Sopra",
                                Contact::Group::FAMILY);

    lContactManager.mAddContact("Gaurav",
                                "Dingra",
                                9911001101,
                                9972221111,
                                "kgraurav@gmail.com",
                                "Noida",
                                "Mentor Graphics",
                                Contact::Group::FRIENDS);

    //lContactManager.mPrintShortedFirstName();
    lContactManager.mPrintShortedLastName();
}