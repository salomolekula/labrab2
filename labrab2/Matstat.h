#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

void matstat(std::vector<int> vctCount, std::vector<std::string> vctName);
void middle(std::vector<int> vctCount);
void median(std::vector<int> vctCount);
void mode(std::vector<int> vctCount, std::vector<std::string> vctName);

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

	std::cout <<"Среднее значение: " << mid / (vctCount.size()) << std::endl;
}

void median(std::vector<int> vctCount)
{
	std::sort(vctCount.begin(), vctCount.end());//сортировка в одну строку

	const int midNum = vctCount.size() / 2;

	if (!(vctCount.size() % 2))
	{
		std::cout << "Медиана - " << vctCount[midNum] << std::endl;
	}
	else
	{
		std::cout << "Медиана - " << (vctCount[midNum] + vctCount[midNum + 1]) / 2 << std::endl;
	}
}

void mode(std::vector<int> vctCount, std::vector<std::string> vctName)
{
	std::vector<int> vctMode;
	

	int length = vctCount.size();
	std::vector<int> index;
	for (int i = 0; i < length; i++) index.push_back(0);



	for (int i = 0; i < length; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (vctCount[i] == vctCount[j]) index[i] += 1;
		}
	}

	int max = index[0];
	for (int i = 0; i < length; i++)
		if (index[i] > max)
		{
			max = index[i];
		}

	for (int i = 0; i < length; i++)
		if (index[i] == max)
		{
			vctMode.push_back(i);
		}

	//работает, даже если выборка мультимодальна!
	std::cout << "Значение(я) моды: ";
	for (int i = 0; i < vctMode.size(); i++) std::cout << vctCount[vctMode[i]] << " ";
	std::cout << ". Список имен, оценка которых соответствует моде: \n";

	for (int i = 0; i < vctMode.size(); i++)
	{
			std::cout << vctName[vctMode[i]] << "\t";
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