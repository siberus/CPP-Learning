#include <iostream>
//#include <string>

template <class T, class S>
class Pair 
{ 
    private: 
    T m_first;
    S m_second;

    public: 
    Pair(const T& value1, const S& value2) 
        : m_first(value1), m_second(value2) {} 
    
    ~Pair() {}

   T& first() {return m_first;}
   S& second() {return m_second;}

   const T& first() const {return m_first;}
   const S& second() const {return m_second;}
};

int main() 
{ 
    Pair<int, double> p1(6, 7.8); 
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    
    const Pair<double, int> p2(3.4, 5); 
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n'; 
    
    return 0;
}