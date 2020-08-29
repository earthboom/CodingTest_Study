#pragma once

#include "stdafx.h"

int solution_morespicy(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> queScoville(scoville.begin(), scoville.end());

    int _first = 0;
    int _second = 0;
    int _mix = 0;
    while (true)
    {
        if (queScoville.top() > K)
            break;

        if (queScoville.size() < 2)
        {
            answer = -1;
            break;
        }

        ++answer;

        _first = queScoville.top();
        queScoville.pop();
        _second = queScoville.top();
        queScoville.pop();

        _mix = _first + (_second * 2);

        queScoville.push(_mix);
    }

    return answer;
}