#include<iostream>

/*
template <typename T, int SIZE>
void Sort(T (&xArr)[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        int lMinIndex = i;
        for (int j = i; j < SIZE; j++)
        {
            if (xArr[j] < xArr[lMinIndex])
                lMinIndex = j;
        }
        std::swap(xArr[i], xArr[lMinIndex]);
    }
}
*/

//using ComparatorFun = bool (*) (int, int);
//template <typename T, int SIZE>
//void Sort(T (&xArr)[SIZE], ComparatorFun xFn)
template <typename T, int SIZE, typename Cmp>
void Sort(T (&xArr)[SIZE], Cmp xFn) 
{
    for (int i = 0; i < SIZE-1; i++)
    {
        for (int j = 0; j < SIZE-1; j++)
        {
            if (xFn(xArr[j], xArr[j+1]))
            {
                T lTmp = std::move(xArr[j+1]);
                xArr[j+1] = std::move(xArr[j]);
                xArr[j] = std::move(lTmp);
            }
        }
    }
}

inline bool CompareFun(int x, int y)
{
    return x < y;
}

struct CompareObj
{
    public: 
    bool operator()(int x, int y)
    {
        return x< y;
    }

} obj;
int main() 
{
    int arr[] = {3,1,5,2,4};
    //Sort(arr, CompareFun);
    CompareObj b;
    Sort(arr, b);
    for (const auto &e : arr)
        std::cout<<e<<" ";
    std::cout<<std::endl;
}