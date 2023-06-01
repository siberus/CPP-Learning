#include <iostream>

int getNum()
{
    int a;
    do
    {
        std::cout << "Enter a digit: ";
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }else
        {
            break;
        }
    } while (true);
    return a;
}

char getOperator()
{
    char op;
    do
    {
        std::cout << "Enter an operator (\"+\", \"-\", \"*\", \"\\\"): ";
        std::cin >> op;
        if(op == '+' || op == '-' || op == '*' || op == '/')
            break;
    } while (true);
    
    return op;
}

int add(int a, int b)
{return a + b;}

int substract(int a, int b)
{return a - b;}

int mltiply(int a, int b)
{return a * b;}

int divide(int a, int b)
{return a / b;}

int  main()
{
    std::cout << "First digit" << std::endl;
    int a = getNum();
    std::cout << "Second digit" << std::endl;
    int b = getNum();
    char op = getOperator();

    return 0;
}
