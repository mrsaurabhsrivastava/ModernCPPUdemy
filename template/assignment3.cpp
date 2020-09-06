#include<iostream>


template <typename T>
T Add(T x, T y)
{
    return x+y;
}

template <typename T, int SIZE>
T ArraySum(T (&pArr)[SIZE])
{
    T Sum;
    for (int i = 0; i < SIZE; i++)
    {
        Sum += pArr[i];
    }
    return Sum;
}

template <typename T, int SIZE> 
T Max(T (&pArr)[SIZE])
{
    T max = pArr[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (max < pArr[i])
            max = pArr[i];
    }
    return max;
}

template <> const char * Max<const char*, int SIZE>(const char* (&pArr)[SIZE])
{

}
template <typename T, int SIZE>
std::pair<T,T> MinMax(T (&pArr)[SIZE])
{
    T min = pArr[0];
    T max = pArr[0];
    for(int i = 1; i < SIZE; i++)
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
    const char *lArray[5] {"Se", "Sb", "Sc", "Sd", "Sa"};
    const char* lMax = Max(lArray);
    std::cout<<lMax<<std::endl;

}
