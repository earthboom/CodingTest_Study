#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 동적계획법 (Dynamic Programming)
// 도둑질

int Stealing(vector<int> money)
{
	int answer = 0;

	vector<int> one;
	vector<int> two;

	int msize = money.size();
	one.resize(msize, money[0]);
	two.resize(msize, money[1]);

	two[0] = 0;

	for (int i = 2; i <= msize-2; ++i)
 		one[i] = max(one[i - 2] + money[i], one[i - 1]);

	for (int i = 2; i <= msize-1; ++i)
		two[i] = max(two[i - 2] + money[i], two[i - 1]);

	answer = max(one[msize - 2], two[msize - 1]);

	return answer;
}

int fibo(int n)
{
	if (n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibo(n - 2) + fibo(n - 1);
}

int fibo_dynamic(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		int r = 0;
		int a = 0, b = 1;

		for (int i = 2; i <= n; ++i)
		{			
			r = a + b;
			a = b;
			b = r;
		}

		return r;
	}
}