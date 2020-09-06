#ifndef __INTEGER_H__
#define __INTEGER_H__
#include <iostream>
#define __DEBUG__
class Integer 
{
    int *mPtr = nullptr;
    public: 
    Integer(int i)
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
        mPtr = new int{i};
    }

    ~Integer() 
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
        delete mPtr;
    }
    Integer(const Integer &obj)
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
        mPtr = new int{*(obj.mPtr)};
    }

    Integer(Integer &&xRhs)
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
        mPtr = xRhs.mPtr;
        xRhs.mPtr = nullptr;
    }

    Integer & operator=(const Integer &xObj)
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
        if (&xObj == this)
            return *this;
        if (mPtr != nullptr)
            delete mPtr;
        mPtr = new int {*(xObj.mPtr)};
        return *this;
    }

    Integer & operator=(Integer &&xRhs)
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
        if(mPtr != nullptr)
            delete mPtr;
        mPtr = xRhs.mPtr;
        xRhs.mPtr = nullptr;
        return *this;
    }

    int mGetValue() const 
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
        return *mPtr;
    }

    void mSetValue(int i)
    {
        #ifdef __DEBUG__
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        #endif
        *mPtr = i;
    }
};

#endif