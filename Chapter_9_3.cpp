#include <iostream>
#include <cassert>

class IntArray
{
    private:
    int *m_array = nullptr;
    int m_size = 0;

    public:
    IntArray(){}
    IntArray(int size)
    {
        assert(size > 0);
        m_size = size;
        m_array = new int [size];
    }

    ~IntArray()
    {
        if (m_array != nullptr)
        {
            delete[] m_array;
        }
    }

    int& operator[] (const int index)
    {
        assert(index >= 0 && index < m_size);
        return m_array[index];
    }
        
    friend std::ostream& operator<< (std::ostream& out, const IntArray &array);

    //Конструктор копирования
    IntArray(const IntArray& array);

    // Перерузка оператора присваивания
    IntArray& operator=(const IntArray & array);
    
};

std::ostream& operator<< (std::ostream& out, const IntArray &array)
{
    for (int i = 0; i < array.m_size; ++i)
    { 
        out <<  (array.m_array)[i] << " ";
    }
    out << std::endl;
    return out;
}

IntArray fillArray() 
{ 
    IntArray a(6);
    a[0] = 6; 
    a[1] = 7; 
    a[2] = 3; 
    a[3] = 4; 
    a[4] = 5; 
    a[5] = 8; 
    
    return a; 
}

// Конструктор копирования 
IntArray::IntArray(const IntArray& array) 
{
    // Поскольку m_length не является указателем, то мы можем выполнить поверхностное копирование 
    m_size = array.m_size; 
    // m_data является указателем, поэтому нам нужно выполнить глубокое копирование, при условии, что этот указатель не является нулевым 
    if (array.m_array) 
    { 
        // Выделяем память для нашей копии 
        m_array = new int[m_size];
        // Выполняем копирование     
        for (int i=0; i < m_size; ++i) 
        m_array[i] = array.m_array[i]; 
    } 
    else
    m_array = 0;
}

// Оператор присваивания 
IntArray& IntArray::operator= (const IntArray& array) 
{ 
    // Проверка на самоприсваивание
    if (this == &array) 
        return *this;
    // Сначала нам нужно очистить предыдущее значение m_data (члена неявного объекта) 
    delete[] m_array;
    // Поскольку m_size не является указателем, то мы можем выполнить поверхностное копирование 
    m_size = array.m_size;
    // m_data является указателем, поэтому нам нужно выполнить глубокое копирование, при условии, что этот указатель не является нулевым 
    if (array.m_array) 
    { 
        // Выделяем память для нашей копии 
        m_array = new int[m_size]; 
        // Выполняем копирование 
        for (int i=0; i < m_size; ++i) 
        m_array[i] = array.m_array[i]; 
    }
    else 
        m_array = 0;

    return *this;
}

int main ()
{   
    IntArray a = fillArray();
    std::cout << a << '\n';

    IntArray b(1); 
    a = a; 
    b = a; 
    std::cout << b << '\n';

    return 0;
}