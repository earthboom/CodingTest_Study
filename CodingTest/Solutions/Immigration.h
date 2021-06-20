#pragma once

#include "stdafx.h""

// ���α׷��ӽ� - Lv 3

// �̺� Ž�� (Binary search)
// �Ա��ɻ�

unsigned long long Immigration(int n, vector<int> times)
{
	unsigned long long answer = 0;

	sort(times.begin(), times.end());

	int left = 0;
	int right = times[times.size() - 1] * n;
	
	while (left <= right)
	{
		unsigned long long mid = (left + right) / 2;
		unsigned long long cnt = 0;

		for (int& t : times)
			cnt += mid / t;

		if (cnt >= n)
		{
			if (answer == 0)
				answer = mid;
			else
				answer = min(answer, mid);

			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return answer;
}