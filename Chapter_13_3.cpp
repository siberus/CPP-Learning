#include <iostream>
#include <string>

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

template <class S>
class StringValuePair : public Pair<std::string, S>
{
    public:
    StringValuePair(const std::string& key, const S& value) 
        : Pair<std::string, S>(key, value) {}
    
};

int main() 
{ 
    StringValuePair<int> svp("Amazing", 7); 
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n'; 
    
    return 0;
}