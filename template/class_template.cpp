#include "class_template.h"

template <typename T, int SIZE> 
Stack<T,SIZE>::Stack(const Stack &obj)
{
    for (int i = 0; i <= obj.mIndex; i++)
    {
        mData[i] = obj.mData[i];
    }
    mIndex = obj.mIndex;
}
template <typename T, int SIZE> 
void Stack<T, SIZE>::mPush(const T &x)
{
    mData[++mIndex] = x;
}

template <typename T, int SIZE>
void Stack<T, SIZE>::mPop()
{
    --mIndex;
}

template <typename T, int SIZE>
const T & Stack<T, SIZE>::mTop() const
{
    return mData[mIndex];
} 

template <typename T, int SIZE>
bool Stack<T, SIZE>::mIsEmpty() const 
{
    return mIndex == -1;
}

template <typename T, int SIZE>
Stack<T,SIZE> Stack<T,SIZE>::CreateObj() 
{
    return Stack<T,SIZE>();
}

int main () 
{
    Stack<float,10> s = Stack<float,10>::CreateObj();
    s.mPush(10);
    s.mPush(14);
    Stack<float, 10>s1 = s;
    while(!s1.mIsEmpty())
    {
        std::cout<<s1.mTop()<<std::endl;
        s1.mPop();
    }
}