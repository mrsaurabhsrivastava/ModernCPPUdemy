#include<iostream>


template <typename T>
T Add(T x, T y)
{
    return x+y;
}

template <typename T>
T ArraySum(T *pArr, int arrSize)
{
    T Sum;
    for (int i = 0; i < arrSize; i++)
    {
        Sum += pArr[i];
    }
    return Sum;
}

template <typename T> 
T Max(T *pArr, int arrSize)
{
    T max = pArr[0];
    for (int i = 1; i < arrSize; i++)
    {
        if (max < pArr[i])
            max = pArr[i];
    }
    return max;
}

template <typename T>
std::pair<T,T> MinMax(T *pArr, int arrSize)
{
    T min = pArr[0];
    T max = pArr[0];
    for(int i = 1; i < arrSize; i++)
    {
        if (pArr[i]< min)
            min = pArr[i];
        
        if (pArr[i] > max)
            max = pArr[i];
    }
    return std::pair<T, T>{min, max};
}
int main () 
{

}
