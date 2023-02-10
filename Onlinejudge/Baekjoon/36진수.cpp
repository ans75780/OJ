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

1.������ ��, ���� ū ������ ���ڿ��� ���ڸ��� �ٲ��.
2.������ ��, ���� ���� �ߺ��� ���ڿ��� ���ڸ��� �ٲ��.


3. 10������ ��ȯ -> ��� ->�ٽ� 36������ ��ȯ.

�ϴ� ������ ó������ ����.

10�����̶�

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

int	makeDigit(int i, int unit)//N����ŭ ,unit������ ���ض�
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
���ڸ� ����� �迭�� �ʿ��ҰŰ�

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