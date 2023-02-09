// Baekjoon.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//


/*
https://www.acmicpc.net/problem/1181
*/


#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <string.h>
using namespace std;

struct cmp
{
	bool operator()(string dest, string sour)
	{
		if (dest.size() == sour.size())
		{
			int compare = strcmp(dest.c_str(), sour.c_str());

			return compare > 0;
		}
		else
		{
			return dest.size() > sour.size();
		}
	}
};


int main()
{
	priority_queue<string, vector<string>, cmp> wordQueue;
	string	popedWord;

	int wordCount = 0;
	string word;

	cin >> wordCount;

	for (int i = 0; i < wordCount; i++)
	{
		cin >> word;
		wordQueue.push(word);
	}

	while (!wordQueue.empty())
	{
		if (!popedWord.empty() &&
			strcmp(wordQueue.top().c_str(), popedWord.c_str()) == 0)
		{
			wordQueue.pop();
		}
		else
		{
			cout << wordQueue.top() << endl;
			popedWord = wordQueue.top();
			wordQueue.pop();
		}
	}
}
