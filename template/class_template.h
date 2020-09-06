#ifndef __CLASS_TEMPLATE__
#define __CLASS_TEMPLATE__
#include<iostream>

template <typename T, int SIZE>
class Stack
{
    private: 
    T mData[SIZE];
    int mIndex {-1};
    
    public:

    Stack() = default;
    Stack(const Stack &obj);
    //{
    //    mIndex = -1;
    //    for (const auto &v : obj.mData)
    //    {
    //        mData[++mIndex] = v;
    //    }
    //} 
    void mPush(const T &x);
    void mPop();
    const T& mTop() const;
    bool mIsEmpty() const;

    static Stack CreateObj();
};

#endif