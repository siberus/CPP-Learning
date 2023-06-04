#include <iostream>

class Numbers
{
    

    

    public:
    
    int m_num_1;
    int m_num_2;

    void set(int n1, int n2)
    {
        m_num_1 = n1;
        m_num_2 = n2;
    }  

    void print()     
    {
        std::cout << "Numbers (" << m_num_1 << ", " << m_num_2 << ")" << std::endl;
    }
};

int main()
{ 
    Numbers n1; 
    n1.set(3, 3); // инициализируем объект n1 значениями 3 и 3 
    
    Numbers n2 { 4, 4 }; // инициализируем объект n2 значениями 4 и 4 
    
    n1.print();
    n2.print(); 
    
    return 0;
}
