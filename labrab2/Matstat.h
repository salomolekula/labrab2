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

	std::cout <<"������� ��������: " << mid / (vctCount.size()) << std::endl;
}

void median(std::vector<int> vctCount)
{
	std::sort(vctCount.begin(), vctCount.end());//���������� � ���� ������

	const int midNum = vctCount.size() / 2;

	if (!(vctCount.size() % 2))
	{
		std::cout << "������� - " << vctCount[midNum] << std::endl;
	}
	else
	{
		std::cout << "������� - " << (vctCount[midNum] + vctCount[midNum + 1]) / 2 << std::endl;
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

	//��������, ���� ���� ������� ��������������!
	std::cout << "��������(�) ����: ";
	for (int i = 0; i < vctMode.size(); i++) std::cout << vctCount[vctMode[i]] << " ";
	std::cout << ". ������ ����, ������ ������� ������������� ����: \n";

	for (int i = 0; i < vctMode.size(); i++)
	{
			std::cout << vctName[vctMode[i]] << "\t";
	}
}

void cocktailSort(std::vector<int>& input)
{
	// ���� ������������ ���� ���������
	bool swapped = true;
	// ������� ��������� �������
	int start = 0;
	// ������� �������� �������
	int end = input.size() - 1;

	// ���� ��������, ���� �� ����� ������������ �������� � �������
	while (swapped) {
		// ���������� ���� ��� ������ �����, ��� ��� �� ����� ���� true ����� ���������� ��������
		swapped = false;

		// �������� ������ ����� �������, ��� � ����������� ����������
		for (int i = start; i < end; ++i) {
			// ���� ������� ������� ������ ����������
			if (input[i] > input[i + 1]) {
				// ������������ ��������
				std::swap(input[i], input[i + 1]);
				// � ��������� ����
				swapped = true;
			}
		}
		// ���� �� ���� ������� �� ��� ����������� - ������ ������������
		if (!swapped)
			// ��� ������������
			break;
		// ����� ���������� ���� � ��������� � ���������� �����
		swapped = false;
		// �������� ��������� ����� �� ���� �����, ��� ��� ����� ������ ������� ��� �� �����
		--end;
		// ��� ���� ����������� ����������, �� ��� ������ ������
		for (int i = end - 1; i >= start; --i) {
			// ���� ������� ������� ������ ����������
			if (input[i] > input[i + 1]) {
				// ������������ ��������
				std::swap(input[i], input[i + 1]);
				// � ��������� ����
				swapped = true;
			}
		}
		// �������� ��������� ������ �� ���� ������, ��� ��� ����� ����� ������� ��� �� �����
		++start;
	}
}