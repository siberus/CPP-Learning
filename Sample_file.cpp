#include <iostream> 
#include <fstream> 
#include <cstdlib> // для использования функции exit() 

int main() 
{ 
    using namespace std;
    // Класс ofstream используется для записи данных в файл. 
    // Создаем файл SomeText.txt 
    ofstream outf("SomeText.txt"); 
    // Если мы не можем открыть этот файл для записи данных в него, 
    if (!outf) 
    { 
        // то выводим сообщение об ошибке и выполняем функцию exit()
        cerr << "Uh oh, SomeText.txt could not be opened for writing!" << endl; 
        exit(1); 
    } // Записываем в файл следующие две строки 
    outf << "See line #1!" << endl; 
    outf << "See line #2!" << endl; 
    return 0; 
    // Когда outf выйдет из области видимости, то деструктор класса ofstream автоматически закроет наш файл 
    }