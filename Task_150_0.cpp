#include <cassert>
#include <iostream>

class Drob
{
    private:
    int m_numerator;
    int m_denuminator;

    public:
    //Конструктор по умолчанию
    Drob(int numerator = 0, int denumerator = 1) : 
        m_numerator (numerator), m_denuminator(denumerator)
    {
        assert(m_denuminator !=0);
    }

    // Конструктор копирования
    Drob(const Drob &copy) :
        m_numerator(copy.m_numerator), m_denuminator(copy.m_denuminator)
    {
        std::cout << "Copy constructor worked here!\n";
    }

    friend std::ostream& operator<< (std::ostream& out, const Drob &d1);
    int getNumerator() { return m_numerator; }
    void setNumerator(int numerator) { m_numerator = numerator; }
};

std::ostream& operator<< (std::ostream& out, const Drob &d1)
{
    out << d1.m_numerator << "/" << d1.m_denuminator;
    return out;
}

Drob makeNegative(Drob d)
{
    d.setNumerator(-d.getNumerator());
    return d;
}

int main()
{
    int a(7);
    Drob sixSeven(6, 7);

    int b {9};
    Drob eightNine {8, 9};

    int c = 3;
    Drob threeSix = Drob(3, 6);

    Drob dCopy(sixSeven);

    std::cout << dCopy << std::endl;

    std::cout << threeSix << std::endl;

    std::cout << makeNegative(7);

    return 0;
}