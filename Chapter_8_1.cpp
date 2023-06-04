#include <iostream>

double max(double a, double b)
{
    return a > b ? a : b;
}

void swap(int &a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
}

int& getLargestElement(int *arr, const int size)
{   int index = 0;
    for (int  i = 0; i < size; ++i)
    {
        if (arr[i] > arr[index])
        {
            index = i;
        } 
    }
    return arr[index];
}