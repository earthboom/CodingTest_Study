#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 연습문제
// 줄 서는 방법

//======================================================================================
//======================================================================================
long long HTL_Factorial(long long n)
{
	if (n == 1)
		return 1;
	return n * HTL_Factorial(n - 1);
}

void HTL_Recur(vector<int>& _answer, vector<int>& _one, long long& all_n, long long _k, int n)
{
	if (_one.size() == 1)
		return;

	long long c1 = _k / all_n;
	long long c2 = _k % all_n;

	all_n /= n;

	_answer.emplace_back(_one[c1]);
	_one.erase(_one.begin() + c1);
	HTL_Recur(_answer, _one, all_n, c2, n - 1);
}

vector<int> How_to_lineup(int n, long long k)
{
	vector<int> answer;

	long long all_n = HTL_Factorial(n - 1);
	vector<int> One_set;
	for (int i = 0; i < n; ++i)
		One_set.emplace_back(i + 1);

	HTL_Recur(answer, One_set, all_n, k - 1, n - 1);

	answer.emplace_back(One_set[0]);

	return answer;
}
//======================================================================================
//======================================================================================