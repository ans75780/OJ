

/*
https://www.acmicpc.net/problem/1049
*/


#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
	int guitarString = 0;
	int brandCount = 0;
	int result = 0;


	int cheapestPackage = 99999;
	int cheapestSingle = 99999;

	int inputPackageCost;
	int inputSingleCost;


	cin >> guitarString >> brandCount;

	for (int i = 0; i < brandCount; i++)
	{
		cin >> inputPackageCost >> inputSingleCost;

		cheapestPackage = min(inputPackageCost, cheapestPackage);
		cheapestSingle = min(inputSingleCost, cheapestSingle);
	}

	if (cheapestPackage > cheapestSingle * 6)//��ǰ���� ��Ʈ������ �� ��� �ٷ� ����
	{
		result = cheapestSingle * guitarString;
		cout << result;
		return 0;
	}
	/*
	������� ������ ��Ű���� ��ǰ���� �γ�,
	�߰������� ������ ������ ��Ȳ�� ���� ���.
	*/
	while (guitarString > 0)
	{
		if (guitarString >= 6)
		{
			result += cheapestPackage;
			guitarString -= 6;
		}
		else if (cheapestPackage < cheapestSingle * guitarString)//���� ������ 6�� �����ε�
		{
			result += cheapestPackage;
			guitarString = 0;
		}
		else
		{
			result += cheapestSingle;
			guitarString--;
		}
	}
	cout << result;

	return 0;
}