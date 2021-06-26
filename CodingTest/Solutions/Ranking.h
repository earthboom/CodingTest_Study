#pragma once

#include "stdafx.h"

// ���α׷��ӽ� - Lv 3

// �׷��� (graph)
// ����

void Ranking_Floyd_Warshall(int& _n, vector<vector<bool>>& _results)
{
	for (int k = 1; k <= _n; ++k)
	{
		for (int i = 1; i <= _n; ++i)
		{
			for (int j = 1; j <= _n; ++j)
			{
				if (_results[i][k] && _results[k][j])
					_results[i][j] = true;
			}
		}
	}
}

int Ranking(int n, vector<vector<int>> results)
{
	int answer = 0;

	vector<vector<bool>> vecResult(101, vector<bool>(101, false));
	
	for (vector<int>& r : results)
	{
		vecResult[r[0]][r[1]] = true;
	}

	//Ranking_Floyd_Warshall(n, vecResult);
	[](int& _n, vector<vector<bool>>& _results) {
		for (int k = 1; k <= _n; ++k)
		{
			for (int i = 1; i <= _n; ++i)
			{
				for (int j = 1; j <= _n; ++j)
				{
					if (_results[i][k] && _results[k][j])
						_results[i][j] = true;
				}
			}
		}
	}(n, vecResult);


	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (vecResult[i][j] || vecResult[j][i])
				++cnt;
		}

		if (cnt == (n - 1))
			++answer;
	}

	return answer;
}