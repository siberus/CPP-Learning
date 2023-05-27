#include <iostream>
#include <string>
#include <algorithm>

 struct Student
    {
        std::string name;
        int score; 
    };
   
int getInt()
{
    int digit{0};
    while (true)
        {
        // std::cout << "Enter a number from 0 to 100." << std::endl;
        std::cin >> digit;
        //Проверка на int
        if (std::cin.fail())
        {
                std::cin.clear();
                std::cin.ignore(32767,'\n');
                std::cout << "Input is invalid. Please try again.\n";
        }
        else
        {
                std::cin.ignore(32767,'\n');
                if ((0<=digit) && (digit <= 100))
                {
                    return digit;
                }
                else
                {
                    std::cout << "Digit must be between 0 and 100. Please try again.\n";
                }
        }
        }
}

void SelectionSort(Student *array, int size) 
{
    // Перебираем каждый элемент массива 
    for (int startIndex = 0; startIndex < size; ++startIndex) 
    { 
        // smallestIndex - это индекс наименьшего элемента, который мы обнаружили до этого момента 
        int smallestIndex = startIndex; 
        // Ищем наименьший элемент среди оставшихся в массиве (начинаем со startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) 
        { 
            // Если текущий элемент больше нашего предыдущего найденного наименьшего элемента, 
            if (array[smallestIndex].score < array[currentIndex].score) // СРАВНЕНИЕ ВЫПОЛНЯЕТСЯ ЗДЕСЬ 
            // то это наш новый наименьший элемент в этой итерации 
            smallestIndex = currentIndex; 
        }
        // Меняем местами наш стартовый элемент с найденным наименьшим элементом 
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

void printStudents(Student *array, int size)
{
    for (int index = 0; index < size; ++index)
    {
        std::cout << array[index].name << " got a grade of " << array[index].score << std::endl;
    }   
}

int main()
{
   
    std::cout << "Enter a number of students (from 0 to 100): " << std::endl;
    int numStudents = getInt();
    Student *students = new Student[numStudents];
    for (int i = 0; i < numStudents; ++i) 
    {
        std::cout << "Enter a name of " << i+1 << " student: " << std::endl;
        std::cin >> students[i].name;
        std::cout << "Enter a score of " << i+1 << " student (from 0 to 100): " << std::endl;
        students[i].score = getInt();
    }
    SelectionSort(students, numStudents);
    printStudents(students, numStudents);

    return 0;
}
