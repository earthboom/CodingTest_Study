#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 탐욕법 (Greedy)
// 단속 카메라


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