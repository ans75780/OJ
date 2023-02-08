// Baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


/*
https://www.acmicpc.net/problem/1259
*/


#include <iostream>

using namespace std;


int main()
{
	int numberList[1000];

	int inputNumber = 0;
	bool bIsCompare;
	while (1)
	{
		cin >> numberList[inputNumber];

		if (numberList[inputNumber] == 0)
			break;
		inputNumber++;
	}
	for (int i = 0; i < inputNumber; i++)
	{
		if (numberList[i] < 10)//예외조건
		{
			cout << "yes" << endl;
			continue;
		}
		bIsCompare = true;


		//정의[1]
		int frontDigit = 1;
		while (frontDigit * 10 < numberList[i])
		{
			frontDigit *= 10;
		}
		//비교[2]
		while (numberList[i] > 0)
		{

			int numberHead = numberList[i] / frontDigit;
			int numberTail = numberList[i] % 10;

			if (numberHead != numberTail)
			{
				bIsCompare = false;
				break;
			}
			numberList[i] %= frontDigit;
			numberList[i] /= 10;

			frontDigit /= 100;

			if (numberList[i] < 10)
				break;
		}
		//출력[3]
		if (bIsCompare)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}
