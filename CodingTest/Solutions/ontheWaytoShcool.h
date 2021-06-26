#pragma once

#include "stdafx.h"

// ���α׷��ӽ� - Lv 3

// ������ȹ�� (Dynamic Programming)
// ���

int ontheWaytoShcool(int m, int n, vector<vector<int>> puddles)
{
	int answer = 0;

	vector<vector<int>> Tile(m, vector<int>(n, -1));
	Tile[0][0] = 1;

	for (vector<int>& p : puddles)
		Tile[p[0] - 1][p[1] - 1] = 0;
	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (Tile[i][j] == -1)
			{
				if (i == 0 && j == 0)
					continue;
				else if (i == 0)
					Tile[i][j] = Tile[i][j - 1] % 1000000007;
				else if (j == 0)
					Tile[i][j] = Tile[i - 1][j] % 1000000007;
				else
					Tile[i][j] = Tile[i][j - 1] + Tile[i - 1][j] % 1000000007;
			}
		}
	}

	answer = Tile[m - 1][n - 1];

	return answer;
}