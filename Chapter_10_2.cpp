#include <iostream>
#include <string>

class Fruit
{
    std::string m_name;
    std::string m_color;

    public:
    Fruit(std::string name, std::string color)
        : m_name(name), m_color(color) 
    {}

    std::string getName() const {return m_name;}
    std::string getColor()const {return m_color;}
   
};

class Apple: public Fruit
{
    double m_fiber;

    public:
    Apple(std::string name = "apple", std::string colour = "red")
        : Fruit(name, colour)
        {}
};

class Banana: public Fruit
{
    public:
    
    Banana()
        : Fruit("banana", "yellow")
        {}
};

class GrannySmith: public Apple
{
    public:
    GrannySmith(std::string name = "Granny Smith apple", std::string color = "green" )
        : Apple(name, color)
        {}
};


int main() 
{ 
    Apple a("red"); 
    Banana b; 
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}