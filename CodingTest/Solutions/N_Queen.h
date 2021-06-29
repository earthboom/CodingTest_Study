#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 연습문제
// N-Queen

//======================================================================================
// 실패작
//======================================================================================
bool promising(int t, vector<int>& p)
{
	for (int i = 0; i < t; ++i)
	{
		if (p[t] == p[i] || (t - i) == abs(p[t] - p[i]))
			return false;
	}
	return true;
}

void NQ_DFS_Backtraking(int t, int& _n, int& _answer, vector<int>& p)
{
	if (t == _n)
	{
		++_answer;
		return;
	}

	for (int i = 0; i < _n; ++i)
	{
		p[t] = i;

		if (promising(t, p))
			NQ_DFS_Backtraking(t + 1, _n, _answer, p);
	}
}

int N_Queen_02(int n)
{
	int answer = 0;

	vector<int> place(n * n, 0);

	NQ_DFS_Backtraking(0, n, answer, place);

	return answer;
}
//======================================================================================
//======================================================================================



//======================================================================================
//======================================================================================
void NQ_DFS(vector<vector<bool>>& p, int& _answer, int _row)
{
	if (_row == p.size())
	{
		++_answer;
		return;
	}

	for (int col = 0; col < p[_row].size(); ++col)
	{
		bool isSet = true;
		for (int i = _row - 1, j = 1; i >= 0; --i, ++j)
		{
			bool condition_0 = p[i][col];
			bool condition_1 = col - j >= 0 && p[i][col - j];	// left diagonal
			bool condition_2 = col + j < p.size() && p[i][col + j]; // right diagonal

			if (condition_0 || condition_1 || condition_2)
			{
				isSet = false;
				break;
			}
		}

		if (isSet)
		{
			p[_row][col] = true;
			NQ_DFS(p, _answer, _row + 1);
			p[_row][col] = false;
		}
	}
}

int N_Queen(int n)
{
	int answer = 0;
	vector<vector<bool>> place(n, vector<bool>(n, false));

	NQ_DFS(place, answer, 0);

	return answer;
}
//======================================================================================
//======================================================================================