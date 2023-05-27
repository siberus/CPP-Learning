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
    int items[MAX_ITEMS];
    items[HEALTH_POISON] = 3;
    items[TORCHS] = 6;
    items[ARROWS] = 12;
    std::cout <<"Total items of player: " << countTotalItems(items, MAX_ITEMS);

    return 0;

}

