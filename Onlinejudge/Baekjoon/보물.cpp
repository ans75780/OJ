

/*

https://www.acmicpc.net/problem/1026

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	int	vecSize;
	int inputNumber;
	int total = 0;

	vector<int>	vecNumberA;
	vector<int>	vecNumberB;

	cin >> vecSize;

	vecNumberA.reserve(vecSize);
	vecNumberB.reserve(vecSize);

	for (int i = 0; i < vecSize; i++)
	{
		cin >> inputNumber;
		vecNumberA.push_back(inputNumber);
	}
	for (int i = 0; i < vecSize; i++)
	{
		cin >> inputNumber;
		vecNumberB.push_back(inputNumber);
	}

	sort(vecNumberA.begin(), vecNumberA.end(),greater<int>());
	sort(vecNumberB.begin(), vecNumberB.end(), less<int>());

	for (int i = 0; i < vecSize; i++)
	{
		total += vecNumberA[i] * vecNumberB[i];
	}
	
	cout << total << endl;

	return 0;
}