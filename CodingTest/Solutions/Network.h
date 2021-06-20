#pragma once

#include "stdafx.h"

// ���α׷��ӽ� - Lv 3

// ����/�ʺ� �켱 Ž�� (DFS / BFS)
// ��Ʈ��ũ

int Network(int n, vector<vector<int>> computers)
{
	int answer = 0;

	size_t cnt = computers.size();
	vector<vector<int>> tree(cnt);
	
	for (size_t i = 0; i < cnt; ++i)
	{
		for (size_t j = 0; j < cnt; ++j)
		{
			if (i == j || computers[i][j] == 0)
				continue;

			tree[i].emplace_back(j);
		}
	}

	vector<bool> visit(cnt, false);

	for (int i = 0; i < tree.size(); ++i)
	{
		if (visit[i])
			continue;

		queue<int> que;
		que.emplace(i);
		visit[i] = true;

		while (!que.empty())
		{
			int start = que.front();
			que.pop();

			for (size_t j = 0; j < tree[start].size(); ++j)
			{
				int end = tree[start][j];
				if (!visit[end])
				{
					visit[end] = true;
					que.emplace(end);
				}
			}
		}

		++answer;
	}

	return answer;
}