#pragma once

#include "stdafx.h"

int get_Parent(vector<int>& p, int x)
{
	if (p[x] == x)
		return x;

	p[x] = get_Parent(p, p[x]);
	return p[x];
}

void union_Parent(vector<int>& p, int s, int e)
{
	s = get_Parent(p, s);
	e = get_Parent(p, e);

	if (s < e)
		p[e] = s;
	else
		p[s] = e;
}

bool find_Parent(vector<int>& p, int s, int e)
{
	s = get_Parent(p, s);
	e = get_Parent(p, e);

	if (s == e)
		return true;
	else
		return false;
}

int Connecting_islands(int n, vector<vector<int>> costs)
{
	int answer = 0;

	vector<pair<int, pair<int, int>>> lineVec;
	vector<int> parent;

	for (int i = 0; i < n; ++i)
		parent.emplace_back(i);

	for (int i = 0; i < costs.size(); ++i)
	{
		auto p = make_pair(costs[i][2], make_pair(costs[i][0], costs[i][1]));
		lineVec.emplace_back(p);
	}

	sort(lineVec.begin(), lineVec.end());

	for (int i = 0; i < lineVec.size(); ++i)
	{
        if (!([](vector<int>& p, int s, int e)->bool 
            {
                s = get_Parent(p, s);
                    e = get_Parent(p, e);

                    if (s == e)
                        return true;
                    else
                        return false;
            }(parent, lineVec[i].second.first, lineVec[i].second.second)))
		{
            answer += lineVec[i].first;
            [](vector<int>& p, int s, int e)
            {
                s = get_Parent(p, s);
                e = get_Parent(p, e);

                if (s < e)
                    p[e] = s;
                else
                    p[s] = e;
            }(parent, lineVec[i].second.first, lineVec[i].second.second);
		}
	}

	return answer;
}







int getParent(vector<int>& _set, int _i)
{
    if (_set[_i] == _i)
        return _i;
    else
        return _set[_i] = getParent(_set, _set[_i]);
}

void unionParent(vector<int>& _set, int _x, int _y)
{
    _x = getParent(_set, _x);
    _y = getParent(_set, _y);

    if (_x < _y)
        _set[_y] = _x;
    else
        _set[_x] = _y;
}

int solution_connectland(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (auto& _c : costs)
        swap(_c[0], _c[2]);

    sort(costs.begin(), costs.end());

    vector<int> set;
    set.resize(n);
    for (int i = 0; i < n; ++i)
        set[i] = i;

    int maxCost = ((n - 1) * n) / 2;
    int _num = 0;
    for (int i = 0; i < costs.size(); ++i)
    {
        int _cost = costs[i][0];

        int _begin = getParent(set, costs[i][1]);
        int _end = getParent(set, costs[i][2]);
        if (_begin == _end)
            continue;
        else
        {
            _num += _cost;
            unionParent(set, costs[i][1], costs[i][2]);
        }
    }

    answer = _num;
    return answer;
}