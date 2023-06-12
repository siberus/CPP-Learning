#include <iostream>
#include <cassert>
#include <cstdint>

class Average
{
    int32_t m_sum;
    int8_t m_count;

    int32_t m_avg;

    public:
    Average(int32_t sum = 0, int8_t count = 0) 
    {
        m_sum = sum;
        m_count = count;
        if (m_count != 0)
            m_avg = sum/count;
        else
            m_avg = 0;

        
        
    }

    friend std::ostream& operator<<  (std::ostream& out, Average avg);

    Average& operator+= (int nextElement)
    {
        m_sum+=nextElement;
        m_count++;
        m_avg = m_sum / m_count;
        return *this;
    }


};

std::ostream& operator<<  (std::ostream& out, Average avg)
{
    std::cout << avg.m_avg;
    return out;
}

int main()
{
    Average avg; 
    avg += 5; 
    std::cout << avg << '\n'; // 5 / 1 = 5 
    avg += 9; 
    std::cout << avg << '\n'; // (5 + 9) / 2 = 7 
    avg += 19; 
    std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11 
    avg += -9; 
    std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6 
    (avg += 7) += 11; // выполнение цепочки операций 
    std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7 
    Average copy = avg;
    std::cout << copy << '\n';
    return 0;
}
