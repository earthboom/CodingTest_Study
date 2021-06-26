#pragma once

// ���� ��ȹ�� ( Dynamic Programming )

#include "stdafx.h"

vector<int> coins = { 1, 3, 4 };
bool ready[30] = { false, };
int value[30] = { 0, };

//���
int DP_solution_0(int x)
{
	if (x < 0)
		return numeric_limits<int>::max() - 1;
	if (x == 0)
		return 0;
	if (ready[x])
		return value[x];

	int b = numeric_limits<int>::max() - 1;
	for (int& c : coins)
	{
		int t = DP_solution_0(x - c) + 1;
		b = min(b, t);
	}

	ready[x] = true;
	value[x] = b;

	return b;
}

//for��
int DP_solution_1(int n)
{
	value[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		value[i] = numeric_limits<int>::max() - 1;
		for (int& c : coins)
		{
			if (i - c >= 0)
				value[i] = min(value[i], value[i - c] + 1);
		}
	}

	return value[n];
}

//�ش� ����
void DP_solution_2(int n)
{
	int first[30] = { 0, };

	value[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		value[i] = numeric_limits<int>::max() - 1;
		for (int& c : coins)
		{
			if ((i - c >= 0) && (value[i - c] + 1 < value[i]))
			{
				value[i] = value[i - c] + 1;
				first[i] = c;
			}
		}
	}

	while (n > 0)
	{
		if (first[n] == 0)
			continue;

		cout << first[n] << endl;
		n -= first[n];
	}
}

// ���� ���� ����
int DP_solution_3(int n)
{
	vector<int> count(n + 1, 0);

	count[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int& c : coins)
		{
			if (i - c >= 0)
				count[i] += count[i - c];
		}
	}

	return count[n];
}