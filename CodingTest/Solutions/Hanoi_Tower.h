#pragma once

#include "stdafx.h"

// ���α׷��ӽ� - Lv 3

// ��������
// �ϳ����� ž

//======================================================================================
//======================================================================================
void Hanoi_move(int _n, vector<vector<int>>& _answer, int start, int mid, int end)
{
	if (_n == 1)
		_answer.push_back({start, end});
	else
	{
		Hanoi_move(_n - 1, _answer, start, end, mid);
		_answer.push_back({ start, end });
		Hanoi_move(_n - 1, _answer, mid, start, end);
	}
}

vector<vector<int>> Hanoi_Tower(int n)
{
	vector<vector<int>> answer;

	Hanoi_move(n, answer, 1, 2, 3);

	return answer;
}
//======================================================================================
//======================================================================================