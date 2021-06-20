#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 동적계획법 (Dynamic Programming)
// N으로 표현

int get_continue_number(int N, int cnt)
{
	int continueN = 0;

	while (cnt > 0)
	{
		--cnt;
		continueN += N * pow(10, cnt);
	}

	return continueN;
}

int Express_as_N(int N, int number)
{
	if (N == number)
		return 1;

	int answer = -1;

	const int Minimun = 8;
	auto s = vector<set<int>>(Minimun);	
	int idx = 1;

	for (auto& _s : s)
	{
		_s.insert(get_continue_number(N, idx));
		++idx;
	}

	for (int i = 1; i < Minimun; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			for (const auto& v1 : s[j])
			{
				for (const auto& v2 : s[i - j - 1])
				{
					s[i].insert(v1 + v2);
					s[i].insert(v1 - v2);
					s[i].insert(v1 * v2);

					if (v2 != 0)
						s[i].insert(v1 / v2);
				}
			}
		}

		if (s[i].find(number) != s[i].end())
		{
			answer = i + 1;
			break;
		}
	}

	return answer;
}

