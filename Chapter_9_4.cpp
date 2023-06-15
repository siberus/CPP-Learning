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

    friend std::ostream& operator<< (std::ostream& out, FixedPoint &a);
};

std::ostream& operator<< (std::ostream& out, FixedPoint &fp)
{
    out << static_cast<double>(fp);

    return out;
}

int main() 
{ 
/*     FixedPoint a(37, 58); 
    std::cout << a << '\n'; 
    
     FixedPoint b(-3, 9); 
     std::cout << b << '\n'; 
     
     FixedPoint c(4, -7); 
     std::cout << c << '\n'; 
     
     FixedPoint d(-5, -7); 
     std::cout << d << '\n'; 
     
     FixedPoint e(0, -3); 
     std::cout << e << '\n'; 
     
     std::cout << static_cast<double>(e) << '\n';  */

     FixedPoint a(0.03); 
     std::cout << a << '\n'; 
     
     FixedPoint b(-0.03); 
     std::cout << b << '\n'; 
     
     FixedPoint c(4.01); // сохранится, как 4.0099999..., поэтому нам нужно это всё округлить 
     std::cout << c << '\n'; 
     
     FixedPoint d(-4.01);
     std::cout << d << '\n';

     return 0; 
     
}