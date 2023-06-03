// Программа MyArguments 
#include <iostream> 

int main(int argc, char *argv[]) 
{ 
    std::cout << "There are " << argc << " arguments:\n"; 
    // Перебираем каждый аргумент и выводим его порядковый номер и значение 
    for (int count=0; count < argc; ++count) 
    std::cout << count << " " << argv[count] << '\n'; 
    
    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::getchar();

    return 0; 
}