#pragma once

#include "stdafx.h"

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