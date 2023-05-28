#include <iostream>


void printWord(const char *p_word)
{
    while(*p_word !='\0')
    {
        std::cout << *p_word;
        ++p_word;
    }
    std::cout << std::endl;


    
}

int main()
{
    char word[] = "Hello, world!";
    printWord(word);
    return 0;
}