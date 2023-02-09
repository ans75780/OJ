
// Baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


/*
https://www.acmicpc.net/problem/1181
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

bool	inNumber666(int number)
{
	string numberStr;

	numberStr = to_string(number);

	int		count = 0;
	for (int i = 0; i < numberStr.size() - 2; i++)
	{
		if (numberStr[i] != '6')
			continue;
		count = 0;
		for (int j = i; j < i + 3; j++)
		{
			if (numberStr[j] == '6')
				count++;
			else
				break;
		}
		if (count >= 3)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int movieNumber = 666;

	int index = 0;
	int findNumber = 0;

	cin >> findNumber;

	while (1)
	{
		if (inNumber666(movieNumber))
		{
			index++;
			if (index == findNumber)
				break;
		}
		movieNumber++;
	}

	cout << movieNumber;

	return 0;
}



