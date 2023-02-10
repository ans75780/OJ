

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

	if (cheapestPackage > cheapestSingle * 6)//단품가가 세트가보다 쌀 경우 바로 구매
	{
		result = cheapestSingle * guitarString;
		cout << result;
		return 0;
	}
	/*
	여기까지 왔으면 패키지가 단품보다 싸나,
	추가적으로 낱개로 구매할 상황이 나온 경우.
	*/
	while (guitarString > 0)
	{
		if (guitarString >= 6)
		{
			result += cheapestPackage;
			guitarString -= 6;
		}
		else if (cheapestPackage < cheapestSingle * guitarString)//줄의 개수가 6개 이하인데
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