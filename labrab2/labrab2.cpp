// labrab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "RadomNames.h"
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
void matstat(std::vector<int> vctCount, std::vector<std::string> vctName);
void middle(std::vector<int> vctCount);
void median(std::vector<int> vctCount);
void mode(std::vector<int> vctCount, std::vector<std::string> vctName);



int main()
{
	setlocale(LC_ALL, "rus");     // Изменение кодировки программы
	SetConsoleOutputCP(1251);     // Изменение кодировки консоли
	SetConsoleCP(1251);
	system("chcp 1251");
	std::vector<int> vctCount;
	std::vector<std::string> vctName;
	//recursionLink: - ссылка для рекурсии, насчёт которой передумал
	std::cout << "Выберете, какое действие совершить:\n 1) Демонстрационный анализ на дефолтных входных значениях(введите 1)\n 2) Анализ на случайных входных значениях(введите 2) \n 3)Анализ на входных значениях от самого пользователя(введите 3)";
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

	iteraionMethod(vctCount, vctName);
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
	for (const auto& i : vctCount) {
		std::cout << i << "\t";
	}
}

void iteraionMethod(std::vector<int>& vctCount, std::vector<std::string>& vctName)
{
	for (auto iterName{ vctName.begin() }; iterName != vctName.end(); iterName++)
	{
		std::cout << *iterName << "\t";
	}

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

//---------------------------------------------------------------------------------------матстат

void matstat(std::vector<int> vctCount, std::vector<std::string> vctName)
{
	middle(vctCount);
	median(vctCount);
	mode(vctCount, vctName);
}

void middle(std::vector<int> vctCount)
{
	double mid = 0;
	for (auto iterCount{ vctCount.begin() }; iterCount != vctCount.end(); iterCount++)
	{
		mid += *iterCount;
	}

	std::cout << mid / (vctCount.size());
}

void median(std::vector<int> vctCount)
{
	std::sort(vctCount.begin(), vctCount.end());//сортировка в одну строку

	const int midNum = vctCount.size() / 2;

	if (!(vctCount.size() % 2))
	{
		std::cout << "Медиана - " << vctCount[midNum];
	}
	else
	{
		std::cout << "Медиана - " << (vctCount[midNum] + vctCount[midNum + 1]) / 2;
	}
}

void mode(std::vector<int> vctCount, std::vector<std::string> vctName)
{
	int number =vctCount[0];
	int mode = number;

	const int length = vctCount.size();
	std::vector<int> index;
	for (int i = 0; i < length; i++) index.push_back(0);

	

	for (int i = 0; i < length; i++)
	{
		for (int j = 1; j < length; j++)
		{
			if (vctCount[i] = vctCount[j]) index[i] += 1;
		}
	}

	int max = index[0];
	for (int i = 1; i < length; i++)
		if (index[i] > max)
		{
			max = index[i];
		}
	//работает, даже если выборка мультимодальна!
	std::cout << "Значение моды: " << mode << ". Список имен, оценка которых соответствует моде: \n";

	for (int i = 0; i < length; i++)
	{
		if (vctCount[i] == mode)
		{
			std::cout << vctName[i] << "\t";
		}
	}
}

void cocktailSort(std::vector<int>& input)
{
	// флаг перестановки двух элементов
	bool swapped = true;
	// счетчик начальной позиции
	int start = 0;
	// счетчик конечной позиции
	int end = input.size() - 1;

	// цикл работает, пока мы можем переставлять элементы в векторе
	while (swapped) {
		// сбрасываем флаг при начале цикла, так как он может быть true после предыдущей итерации
		swapped = false;

		// проходим циклом слева направо, как в пузырьковой сортировке
		for (int i = start; i < end; ++i) {
			// если текущий элемент больше следующего
			if (input[i] > input[i + 1]) {
				// переставляем элементы
				std::swap(input[i], input[i + 1]);
				// и поднимаем флаг
				swapped = true;
			}
		}
		// если ни один элемент не был переставлен - вектор отсортирован
		if (!swapped)
			// без комментариев
			break;
		// иначе сбрасываем флаг и переходим к следующему этапу
		swapped = false;
		// сдвигаем указатель конца на один влево, так как самый правый элемент уже на месте
		--end;
		// ещё одна пузырьковая сортировка, но уже справа налево
		for (int i = end - 1; i >= start; --i) {
			// если текущий элемент больше следующего
			if (input[i] > input[i + 1]) {
				// переставляем элементы
				std::swap(input[i], input[i + 1]);
				// и поднимаем флаг
				swapped = true;
			}
		}
		// сдвигаем указатель начала на один вправо, так как самый левый элемент уже на месте
		++start;
	}
}