#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <functional> //Если не используем functions то не нужно

struct Student
{
    std::string name{};
    int grade{};
};

int main()
{
    std::array<Student, 8> arr
    { 
        {
            { "Albert", 3 }, 
            { "Ben", 5 }, 
            { "Christine", 2 }, 
            { "Dan", 8 }, // Dan имеет больше всего баллов (8). 
            { "Enchilada", 4 }, 
            { "Francis", 1 }, 
            { "Greg", 3 }, 
            { "Hagrid", 5 } 
        } 
    };

//Используем auto. Храним лямбду с её реальным типом (какой тип - так и не разорался)
/* auto isSmallest{
    [](const Student &a, const Student &b) -> bool
                            {return (a.grade < b.grade);}
}; */

// Обычный указатель на функцию. Лямбда не может ничего захватить - здесь не сработало
/* bool (*isSmallest)(Student, Student){
    [](const Student &a, const Student &b)
                            {return (a.grade < b.grade);}
}; */

// Используем std::function. Лямбда может захватывать переменные.
std::function isSmallest
{
    [](const Student &a, const Student &b)
                            {return (a.grade < b.grade);}
};

auto best = std::max_element(arr.begin(), arr.end(), isSmallest);

std::cout << best->name << "is the best student. " << std::endl;
    return 0;
}