#include <iostream>

int binarySearch(int *array, int target, int min, int max) 
{
    
    if(min > max)
        return -1;
    
    int index = (max-min)/2+min;;
    if(array[index] == target)
        return index;
    else
    {
        if(array[index] > target)
        {
            return binarySearch(array, target, min, index-1);
        }   
        else
        {
            return binarySearch(array, target, index+1, max);
        }   
    }
    
} 

int main() 
{ 
    int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 }; 
    std::cout << "Enter a number: "; 
    int x; 
    std::cin >> x; 
    
    int index = binarySearch(array, x, 0, 14); 
    
    if (index != -1) 
    std::cout << "Good! Your value " << x << " is on position "<< index << " in array!\n"; 
    else 
    std::cout << "Fail! Your value " << x << " isn't in array!\n"; 
    std::cin.fail();
    std::cin.ignore(32767,'\n');
    std::cin.get();
    return 0;
}