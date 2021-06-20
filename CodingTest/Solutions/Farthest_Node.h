#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 그래프 (Graph)
// 가장 먼 노드

int Farthest_Node(int n, vector<vector<int>> edge)
{
	int answer = 0;

	vector<vector<int>> graph(n + 1);

	for (size_t i = 0; i < edge.size(); ++i)
	{
		graph[edge[i][0]].emplace_back(edge[i][1]);
		graph[edge[i][1]].emplace_back(edge[i][0]);
	}

	vector<bool> visit(n + 1, false);
	vector<int> dist(n + 1, 0);
	queue<int> que;

	que.emplace(1);	// 1을 기준으로 하기 때문
	visit[1] = true;

	while (!que.empty())
	{
		int start = que.front();
		que.pop();

		for (size_t i = 0; i < graph[start].size(); ++i)
		{
			int end = graph[start][i];
			if (!visit[end])
			{
				visit[end] = true;

				dist[end] = dist[start] + 1;
				que.emplace(end);
			}
		}
	}

	sort(dist.begin(), dist.end(), greater<int>());
	
	for (int& d : dist)
	{
		if (dist[0] == d)
			++answer;
	}

	return answer;
}