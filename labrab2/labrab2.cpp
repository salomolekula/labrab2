// labrab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "RadomNames.h"
#include "Matstat.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <locale.h>

void firstWay(std::vector<int>& vctCount, std::vector<std::string>& vctName);
void secondWay(std::vector<int>& vctCount, std::vector<std::string>& vctName);
void thirdWay(std::vector<int>& vctCount, std::vector<std::string>& vctName);
void range_based_for_loop(std::vector<int> vctCount, std::vector<std::string> vctName);
void iteraionMethod(std::vector<int>& vctCount, std::vector<std::string>& vctName);
void indexMethod(std::vector<int> vctCount, std::vector<std::string> vctName);


int main()
{
	setlocale(LC_ALL, "rus");     // Изменение кодировки программы
	SetConsoleOutputCP(1251);     // Изменение кодировки консоли
	SetConsoleCP(1251);
	system("chcp 1251");
	std::vector<int> vctCount;
	std::vector<std::string> vctName;
	//recursionLink: - ссылка для рекурсии, насчёт которой передумал
	std::cout << "Выберете, какое действие совершить:\n 1) Демонстрационный анализ на дефолтных входных значениях(введите 1)\n 2) Анализ на случайных входных значениях(введите 2) \n 3)Анализ на входных значениях от самого пользователя(введите 3)" << std::endl;
	int n;
	std::cin >> n;
	
	switch (n)
	{
	case 1:

		firstWay(vctCount, vctName);
		break;
	case 2:

		secondWay(vctCount, vctName);
		break;
	case 3:

		thirdWay(vctCount, vctName);
		break;
	default:

		std::cout << "Key is undefined" << "\n";
		break;
	}

	indexMethod(vctCount, vctName);
	matstat(vctCount, vctName);
	std::cout << "Желаете добавть или убрать студента? Добаить - 1, убрать - 0. В ином случае введите любоё другой знак." << std::endl;
	int upply;
	std::cin >> upply;

	if (upply == 1)
	{



		std::cout << "Сначала введите имя студента, затем его баллы" << std::endl;
		int newCount;
		std::string newName;
		std::cin >> newName >> newCount;
		vctName.push_back(newName);
		vctCount.push_back(newCount);
		//чтобы создать рекурсию, хотел обратиться к оператору goto. Передумал :)
	}
	else if (upply == 0) {


		std::cout << "Введите номер студента для удаления" << std::endl;
		int numberStud;
		std::cin >> numberStud;
		vctCount.erase(vctCount.begin() + numberStud - 1);
		vctName.erase(vctName.begin() + numberStud - 1);//учитываем, что в журналах список начинается с 1, а не с 0
	}
	else{

		std::cout << "Key is undefined" << "\n";
	}

	
		//	for (int i = 0; i < 10; i++)
	//	{
	//		std::cout << vctName[i] << "\t" << vctCount[i] << std::endl;
	//	}

	}

//------------------------------------------------------------------------------ наполнение
void firstWay(std::vector<int>& vctCount, std::vector<std::string>& vctName)
{
	vctName = {"Тимур", "София", "Глеб", "Миша", "Надира", "Юн ХИ", "Арина", "Анна", "Гоша", "Виктор"};
	vctCount = {70, 69, 90, 89, 75, 60, 78, 70, 96, 51};
}

void secondWay(std::vector<int>& vctCount, std::vector<std::string>& vctName)
{
	srand(time(NULL));

	int count;
	std::cout << "Введите количество студентов:";
	std::cin >> count;

	for (int i = 0; i < count; i++)
	{
		vctName.push_back(randomingName(rand() % 75));
		vctCount.push_back(rand() % 100);
	}
}

void thirdWay(std::vector<int>& vctCount, std::vector<std::string>& vctName)
{
	int count;
	std::cout << "Введите количество студентов:";
	std::cin >> count;
	int ball;
	std::string name;
	std::cout << "Введите сначала имя студента, потом его баллы." << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cin >> name >> ball;
		vctName.push_back(name);
		vctCount.push_back(ball);

	}
}


//------------------------------------------------------------------------------------------- вывод

void range_based_for_loop(std::vector<int> vctCount, std::vector<std::string> vctName)
{
	for (const auto& i : vctName) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	for (const auto& i : vctCount) {
		std::cout << i << "\t";
	}std::cout << std::endl;
}

void iteraionMethod(std::vector<int>& vctCount, std::vector<std::string>& vctName)
{
	for (auto iterName{ vctName.begin() }; iterName != vctName.end(); iterName++)
	{
		std::cout << *iterName << "\t";
	}
	std::cout << std::endl;

	for (auto iterCount{ vctCount.begin() }; iterCount != vctCount.end(); iterCount++)
	{
		std::cout << *iterCount << "\t";
	}
}

void indexMethod(std::vector<int> vctCount, std::vector<std::string> vctName)
{
	for (int i = 0; i < vctCount.size(); i++)
	{
		std::cout << vctName[i] << "\t" << vctCount[i] << std::endl;
	}
}
