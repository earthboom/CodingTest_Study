#pragma once

#include "stdafx.h"

// ���α׷��ӽ� - Lv 3

// ������ȹ�� (Dynamic Programming)
// ���� �ﰢ��

int maxValue(int& _a, int& _b)
{
	return _a > _b ? _a : _b;
}

int Integer_Triangle(vector<vector<int>> triangle)
{
	int answer = 0;

	vector<vector<int>> intSum(501, vector<int>(501));
	answer = intSum[0][0] = triangle[0][0];

	for (int i = 1; i < triangle.size(); ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			// ó��
			if (j == 0)
				intSum[i][j] = intSum[i - 1][j] + triangle[i][j];
			// ������
			else if (j == i)
				intSum[i][j] = intSum[i - 1][j - 1] + triangle[i][j];
			// �߰�
			else
				intSum[i][j] = [](int& _a, int& _b) ->int { return _a > _b ? _a : _b; }(intSum[i - 1][j - 1], intSum[i - 1][j]) + triangle[i][j];
				//intSum[i][j] = maxValue(intSum[i - 1][j - 1], intSum[i - 1][j]) + triangle[i][j];

			answer = [](int& _a, int& _b) ->int { return _a > _b ? _a : _b; }(answer, intSum[i][j]);
			//answer = maxValue(answer, intSum[i][j]);
		}
	}

	return answer;
}