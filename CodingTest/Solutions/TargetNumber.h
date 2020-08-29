#pragma once

#include "stdafx.h"

void circle_number(vector<int>& _num, int _cnt, int _sum, int& _a, const int& _t)
{
    if ((_num.size() - 1) == _cnt)
    {
        if (_sum == _t)
            ++_a;
        return;
    }

    circle_number(_num, _cnt + 1, _sum + _num[_cnt + 1], _a, _t);
    circle_number(_num, _cnt + 1, _sum - _num[_cnt + 1], _a, _t);
}

int solution_TargetNumber(vector<int> numbers, int target)
{
    int answer = 0;

    circle_number(numbers, 0, numbers[0], answer, target);
    circle_number(numbers, 0, -numbers[0], answer, target);

    return answer;
}