#include <iostream>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return factorial(n-1)*n;
}

int main ()
{
    int n;
    std::cin >> n;
    std::cout << "Factorial(" << n << ") = " << factorial(n);
    return 0;
}