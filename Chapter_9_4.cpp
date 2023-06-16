#include <iostream>
#include <cmath>
#include <cstdint>

class FixedPoint
{
    std::int16_t m_base; 
    std::int16_t m_decimal;

    public:
    FixedPoint(std::int16_t base = 0, std::int8_t decimal = 0)
        : m_base(base), m_decimal(static_cast<int16_t>(decimal))
    {   
        if (m_decimal > 99)
        {
            m_decimal-=99;
            m_base+=1;
        }
         if (m_decimal < -99)
        {
            m_decimal+=99;
            m_base-=1;
        }
        if (m_base < 0.0 || m_decimal < 0.0) 
        { 
            // Проверяем целую часть 
            if (m_base > 0.0) m_base = -m_base; 
            // Проверяем дробную часть 
            if (m_decimal > 0.0) m_decimal = -m_decimal; 
        }
    }

    FixedPoint(double d)
    {
        m_base = static_cast<int16_t>(d);
        m_decimal = static_cast<int16_t>(round((d-m_base)*100));
    }

    operator double() const 
    { 
        return m_base + static_cast<double>(m_decimal) / 100; 
    }

    friend bool operator==(const FixedPoint &fp1, const FixedPoint &fp2);
    friend std::ostream& operator<< (std::ostream& out, FixedPoint &a);
    friend std::istream& operator>> (std::ostream& out, FixedPoint &a);
    friend FixedPoint operator+(const FixedPoint &fp1, const FixedPoint &fp2);

    FixedPoint operator-() { return FixedPoint(-m_base, -m_decimal); }
};

std::ostream& operator<< (std::ostream& out, FixedPoint &fp)
{
    out << static_cast<double>(fp);

    return out;
}

std::istream& operator>> (std::istream& in, FixedPoint &fp)
{
    double d;
    in >> d;
    fp = FixedPoint(d);

    return in;
}

bool operator== (const FixedPoint &fp1, const FixedPoint &fp2)
{
    return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
}
FixedPoint operator+(const FixedPoint &fp1, const FixedPoint &fp2)
{ 
    return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2)); 
}

void SomeTest() 
{ 
    std::cout << std::boolalpha;
    std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; 
    // оба значения положительные, никакого переполнения
    std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; 
    // оба значения положительные, переполнение
    std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; 
    // оба значения отрицательные, никакого переполнения
    std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; 
    // оба значения отрицательные, переполнение
    std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; 
    // второе значение отрицательное, никакого переполнения
    std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; 
    // второе значение отрицательное, возможно переполнение
    std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; 
    // первое значение отрицательное, никакого переполнения
    std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; 
    // первое значение отрицательное, возможно переполнение
}

int main() 
{ 
    SomeTest(); FixedPoint a(-0.48); 
    std::cout << a << '\n'; 
    std::cout << -a << '\n'; 
    std::cout << "Enter a number: "; // введите 5.678
    std::cin >> a; 
    std::cout << "You entered: " << a << '\n';
    
    return 0; 
     
}