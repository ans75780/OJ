// Baekjoon.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//


/*
https://www.acmicpc.net/problem/1018
*/


#include <iostream>
#include <algorithm>
using namespace std;

//[0]�˻�� ü������ ����� �Լ�
void MakeBoardCase(char*** board, int width, int height, bool startColor)
{
	*board = new char* [height];
	bool color;
	for (int i = 0; i < height; i++)
	{
		(*board)[i] = new char[width];
		(*board)[i][width] = '\0';

		color = startColor;
		for (int j = 0; j < width; j++)
		{
			if (color)
			{
				(*board)[i][j] = 'B';
			}
			else
			{
				(*board)[i][j] = 'W';
			}
			color = !color;
		}
		startColor = !startColor;
	}
}

//[1]�˻�� ü���� ü������ �˻���, �ٽ� ĥ�ؾ� �ϴ� �κ��� �����ϴ� �Լ�

int SolvedPainted(char** board, char** checkBoard, int startX, int endX, int startY, int endY)
{
	int	paintedCount = 0;

	int checkI = 0;
	int checkJ = 0;


	for (int i = startY; i < endY; i++)
	{
		checkJ = 0;
		for (int j = startX; j < endX; j++)
		{
			if (board[i][j] != checkBoard[checkI][checkJ])
			{
				paintedCount++;
			}
			checkJ++;
		}
		checkI++;
	}
	return paintedCount;
}


int main()
{
	int width =		0;
	int height =	0;
	int minPaintCount = 99999;


	char** board;
	char** CheckCase1;
	char** CheckCase2;

	MakeBoardCase(&CheckCase1, 8, 8, 1);
	MakeBoardCase(&CheckCase2, 8, 8, 0);

	cin >> height >> width;
	board = new char* [height];

	for (int i = 0; i < height; i++)
	{
		board[i] = new char[width];

		cin >> board[i];
	}

	for (int i = 0; i < height; i++)
	{
		if (i + 8 > height)
			continue;
		for (int j = 0; j < width; j++)
		{
			if (j + 8 > width)
				continue;

			int paintCount1 = SolvedPainted(board, CheckCase1, j, j + 8, i, i + 8);
			int paintCount2 = SolvedPainted(board, CheckCase2, j, j + 8, i, i + 8);

			minPaintCount = min(minPaintCount, paintCount1);
			minPaintCount = min(minPaintCount, paintCount2);
		}
	}
	cout << minPaintCount;

	/*
	cout << endl << "case1" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << CheckCase1[i];
		cout << endl;
	}

	cout << endl << "case2" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << CheckCase2[i];
		cout << endl;
	}
	*/

}




