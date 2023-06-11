#include <iostream>
#include <string>

class  Mystring
{
private:
    std::string m_str;
public:
     Mystring(std::string str) : m_str(str) {}

     std::string operator() (int index, int count)
     {
        std::string str = "";
        for (int i = index; i < index+count; ++i)
        {
            str +=m_str[i];
        }   
        return str;
     }
    
};

int main()
{
    Mystring string("Hello, world!"); 
    std::cout << string(7, 6); // начинаем с 7 символа (индекса) и возвращаем следующие 6 символов

    return 0;
}