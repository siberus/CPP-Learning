#include <iostream>
#include <exception>

class Fraction
{
    private:
    int m_numerator = 0;
    int m_denumirator = 1;

    public:
    Fraction(int numerator, int denominator) :
        m_numerator(numerator), m_denumirator(denominator) 
        {}

    ~Fraction() {}
};

class descriptive_exception : public std::exception 
{
    private:
    std::string msg_;
    public:
    descriptive_exception(std::string const &message) : msg_(message) { }
    virtual char const *what() const noexcept { return msg_.c_str(); }
};

int main ()
{
    try
    {
        int a, b;
        std::cout << "Enter the numerator: ";
        std::cin >> a;
        std::cout << "Enter the denominator: ";
        std::cin >> b;
        if (b == 0)
        {
            throw descriptive_exception("Your fraction has an invalid denominator.");
        }
        Fraction drob(a, b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}