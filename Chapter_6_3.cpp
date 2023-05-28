#include <iostream>

int getDigit()
{
    int digit;
    while (true)
    {
        std::cin >> digit;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Input is invalid. Please try again.\n";
        }
        return digit;
    }
    
    
}

void changeDigit(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

int main()
{
    int a, b;
    std::cout << "Enter a dgit \"a\": " << std::endl;
    a = getDigit();
    std::cout << "Enter a dgit \"b\": " << std::endl;
    b = getDigit();
    changeDigit(&a,&b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}