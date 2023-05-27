#include <iostream>
//#include <array>

enum Items 
    {
        HEALTH_POISON,
        TORCHS,
        ARROWS,
        MAX_ITEMS
    };

    int countTotalItems(int *arr, int length)
    {
        int count=0;
        for (int i = 0; i < length; i++)
        {
            count +=arr[i];
        }
        

        return count;
    }

int main ()
{
    int items[MAX_ITEMS] = {3, 6, 12};
    std::cout << countTotalItems(items, MAX_ITEMS);

    return 0;

}

