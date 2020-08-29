#pragma once

#include "stdafx.h"

int solution_print(vector<int> priorities, int location)
{
    int answer = 0;

    queue<pair<int, int>> queBase;
    priority_queue<int> queSort;

    for (size_t i = 0; i < priorities.size(); ++i)
    {
        queBase.push(make_pair(i, priorities[i]));
        queSort.push(priorities[i]);
    }

    while (!queBase.empty())
    {
        int _iFirst = queBase.front().first;
        int _iSecond = queBase.front().second;
        queBase.pop();

        if (_iSecond == queSort.top())
        {
            queSort.pop();
            ++answer;

            if (_iFirst == location)
                break;
        }
        else
            queBase.push(make_pair(_iFirst, _iSecond));
    }

    return answer;
}