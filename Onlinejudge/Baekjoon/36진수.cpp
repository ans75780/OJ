/*

https://www.acmicpc.net/problem/1036

*/


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
/*

1.가능한 한, 가장 큰 길이의 문자열의 앞자리를 바꿔라.
2.가능한 한, 가장 많이 중본된 문자열의 앞자리를 바꿔라.


3. 10진수로 변환 -> 계산 ->다시 36진수로 변환.

일단 간단한 처리부터 먼저.

10진법이란

32  2


*/

char	Base36Number[36] = { '0','1','2','3','4','5','6','7','8','9',
							'A','B','C','D','E','F','G','H','I','J','K',
							'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };


int		ToDecimalUnit(char Base36Char)
{
	int i;
	for (i = 0; i < 36; i++)
	{
		if (Base36Char == Base36Number[i])
			break;
	}
	return i;
}

char		to36Base(int	Base36Int)
{
	return Base36Number[Base36Int];
}

int	makeDigit(int i, int unit)//N번만큼 ,unit값으로 곲해라
{
	int result = 1;

	while (i > 0)
	{
		result *= unit;
		i--;
	}
	return result;
}

int ToDecimal(string strBase36)
{
	int result = 0;

	for (int i = strBase36.size(); i > 0; i--)
	{
		int number = ToDecimalUnit(strBase36[strBase36.size() - i]);
		int	unit = makeDigit(i -1, 36);

		result += (number * unit);
	}
	return result;
}

string ToBase36(int Decimal)
{
	string result;

	int unit;

	while (Decimal > 0)
	{
		unit = 1;

		while (1)
		{
			if (unit * 36 > Decimal)
			{
				break;
			}
			unit *= 36;
		}
		result.push_back(to36Base(Decimal / unit));

		Decimal %= unit;
	}
	return result;
}

struct cmp
{
	bool operator()(pair<int, char> dest, pair<int, char> sour)
	{

	}
};



/*
문자를 등록한 배열도 필요할거고

*/

vector<char>	vecSelectedChar;
vector<string>	vecStr;
priority_queue<pair<int, char>, vector<char>, cmp> ChangeCharQueue;



int main()
{
	int				vecStrSize;
	int				selectCount;
	string			inputStr;

	cin >> vecStrSize;

	for (int i = 0; i < vecStrSize; i++)
	{
		cin >> inputStr;




		vecStr.push_back(inputStr);
	}
	cin >> selectCount;


	//



	return 0;
}