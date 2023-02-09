


/*
https://www.acmicpc.net/problem/1003
*/

/*

기존 피보나치는 Top-Down 방식으로 작업해도 괜찮았지만,
여기 피보나치에서 요구하는 것은 짧은(중요) 시간 내에 정해진 값에 도달하는 것입니다.
그러므로 천천히 값을 쌓아서 올라가는 방식인 Bottom-UP 방식으로 진행됩니다.
오히려 코드의 구현은 사람이 피보나치 수열을 만들때의 그것과 유사합니다.

배열에 값을 저장하고, 다음 값이 올때 이를 출력하는 것입니다.
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