#include <iostream>
#include <iomanip>

#include "myFunctions.h"


int main()
{
	setlocale(LC_ALL, "rus");

	//double h;
	//h = readData();
	////std::cout << std::setprecision(2);
	//for (int i = 0; i <= 5; i++)
	//{
	//	double x;
	//	x = calculate(h, static_cast<double>(i));
	//	if (x > 0)
	//		std::cout << "At " << i << " seconds, the ball is at heght: " << x << " meters." << std::endl;
	//	else
	//		std::cout << "At " << i << " seconds, the ball is on the ground."  << std::endl;
	//}

	//int x;
	//x = inputDigit();
	//if (isEven(x))
	//	std::cout << "The digit " << x << " is even!";
	//else
	//	std::cout << "The digit " << x << " is not even!";

	/*int firstDigit;
	firstDigit = inptDigitRus();
	int secondDigit;
	secondDigit = inptDigitRus();
	if (firstDigit > secondDigit)
	{
		std::cout << "Меняем значения местами" << std::endl;
		std::cout << "Меньшее число: " << secondDigit << std::endl;
		std::cout << "Большее число: " << firstDigit << std::endl;
	}
	else
	{
		std::cout << "Меньшее число: " << firstDigit << std::endl;
		std::cout << "Большее число: " << secondDigit << std::endl;
	}*/

	std::string yourName;
	yourName = inputName();
	int age;
	age = inputAge();
	std::cout << "Вы прожили " << ageForLetter(yourName, age) << " лет на каждую букву вашего имени!" << std::endl;
	
	return 0;
}
