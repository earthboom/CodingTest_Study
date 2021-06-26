#pragma once

#include "stdafx.h"

// ���α׷��ӽ� - Lv 3

// Ž��� (Greedy)
// �ܼ� ī�޶�


int Control_Camera(vector<vector<int>> routes)
{
	int answer = 1;

	sort(routes.begin(), routes.end());
	int exit = routes[0][1];

	for (vector<int>& r : routes)
	{
		if (exit < r[0])
		{
			++answer;
			exit = r[1];
		}

		if (exit >= r[1])
			exit = r[1];
	}

	return answer;
}