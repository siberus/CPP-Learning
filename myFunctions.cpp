#include <iostream>
#include "myConstants.h"
#include <string>

using  namespace myConstants;

double readData()
{
	double h;
	std::cout << "Enter the initial height of the tower: ";
	std::cin >> h;
	return h;
}

double calculate(double h, double t)
{
	double x;
	x = h - g * t * t / 2;
	if (x > 0)
		return x;
	else
		return 0;
}

bool isEven(int x)
{
	if (!x % 2)
		return true;
	else
		return false;
}

int inputDigit()
{
	int x;
	std::cout << "Enter a digit: ";
	std::cin >> x;
	return x;
}

int inptDigitRus() 
{
	int x;
	std::cout << "¬ведите целое число: ";
	std::cin >> x;
	return x;
}

std::string inputName()
{
	std::cout << "¬ведите ваше полное им€: ";
	std::string name;
	std::getline(std::cin, name);
	return name;
	
}

int inputAge()
{
	int x;
	std::cout << "¬ведите ваш возраст: ";
	std::cin >> x;
	return x;
}

double ageForLetter(std::string p_name, int p_age)
{
	double f_agePerLettre;
	f_agePerLettre = p_age / static_cast<double>(p_name.length());
	return f_agePerLettre;
}

