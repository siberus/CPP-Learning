#include <iostream>

class Fruit
{
    std::string m_name;
    std::string m_colour;

    public:
    Fruit(std::string name = "", std::string colour = "")
        : m_name(name), m_colour(colour) 
    {}

    std::string getName() const {return m_name;}
    std::string getColour()const {return m_colour;}
    friend std::ostream& operator<< (std::ostream& out, Fruit &f);
};

std::ostream& operator<< (std::ostream& out, Fruit &f)
{
    out << f.m_name << ", " << f.m_colour << ", ";
}

class Apple: public Fruit
{
    double m_fiber;

    public:
    Apple(std::string name, std::string colour, double fiber)
        : Fruit(name, colour), m_fiber(fiber)
        {}
    
    friend std::ostream& operator<< (std::ostream& out, const Apple &a);
};

std::ostream& operator<< (std::ostream& out, const  Apple &a)
{
    out << "Apple (" << a.getName() << ", " << a.getColour() << ", " << a.m_fiber << ")" << std::endl;
    return out;
}


class Banana: public Fruit
{
    public:
    
    Banana(std::string name, std::string colour)
        : Fruit(name, colour)
        {}
    
    friend std::ostream& operator<< (std::ostream& out, const Banana &b);
};

std::ostream& operator<< (std::ostream& out, const Banana &b)
{
    out << "Banana (" << b.getName() << ", " <<b.getColour() << ")" << std::endl;
    return out;
}


int main() 
{ 
    const Apple a("Red delicious", "red", 7.3); 
    std::cout << a; 
    const Banana b("Cavendish", "yellow"); 
    std::cout << b; 
    return 0;
}