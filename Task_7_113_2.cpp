#include <iostream>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return factorial(n-1)*n;
}

int sumNumber(int n)
{
    if (n < 10)
        return n;
    else    
        return sumNumber(n / 10) + (n % 10);
}

void printBinary(unsigned int n)
{
    if(n == 0)
        return ;
    else
    {
        printBinary(n / 2);
        std::cout << (n % 2);
    }   
}

void printUnsigBinary(int n)
{
    if(n == 0)
        std::cout << "0";
    else
        printBinary(static_cast<unsigned int>(n));
}

int main ()
{
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    //std::cout << "Factorial(" << n << ") = " << factorial(n);
    //std::cout << "sumNumber(" << n << ") = " << sumNumber(n);
    //printBinary(n);
    printUnsigBinary(n);
    return 0;
}