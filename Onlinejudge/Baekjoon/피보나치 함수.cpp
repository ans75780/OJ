


/*
https://www.acmicpc.net/problem/1003
*/

/*

���� �Ǻ���ġ�� Top-Down ������� �۾��ص� ����������,
���� �Ǻ���ġ���� �䱸�ϴ� ���� ª��(�߿�) �ð� ���� ������ ���� �����ϴ� ���Դϴ�.
�׷��Ƿ� õõ�� ���� �׾Ƽ� �ö󰡴� ����� Bottom-UP ������� ����˴ϴ�.
������ �ڵ��� ������ ����� �Ǻ���ġ ������ ���鶧�� �װͰ� �����մϴ�.

�迭�� ���� �����ϰ�, ���� ���� �ö� �̸� ����ϴ� ���Դϴ�.
*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int>	CalledFibonacci[40];

pair<int, int> fibonacci(int n, int goal)
{
	pair<int, int>	currentPair;

	if (n == 0)
		currentPair = { 1,0 };

	if (n == 1)
		currentPair = { 0,1 };

	if (n > 1)
	{	
		currentPair.first = CalledFibonacci[n - 1].first + CalledFibonacci[n - 2].first;
		currentPair.second = CalledFibonacci[n - 1].second + CalledFibonacci[n - 2].second;
	}
	CalledFibonacci[n] = currentPair;
	if (n == goal)
	{
		return currentPair;
	}
	return fibonacci(++n, goal);
}

int main()
{
	int		inputCount = 0;
	int		inputNumber = 0;
	vector<int> vecTestNumber;

	cin >> inputCount;

	for (int i = 0; i < inputCount; i++)
	{
		cin >> inputNumber;
		vecTestNumber.push_back(inputNumber);
	}
	
	for (int i = 0; i < inputCount; i++)
	{
		pair<int, int> result;

		if (vecTestNumber[i] == 1)
			result = fibonacci(1, vecTestNumber[i]);
		else
			result = fibonacci(0, vecTestNumber[i]);

		cout << result.first << " " << result.second << endl;

	}
	return 0;
}