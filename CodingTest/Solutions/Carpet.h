#pragma once

#include "stdafx.h"

vector<int> solution_Carpet(int brown, int yellow)
{
    vector<int> answer;

    int _len = (brown / 2) + 2;

    int _x = _len - 3;
    int _y = 3;

    while (_x >= _y)
    {
        if ((_x * _y) == (brown + yellow)) break;

        --_x;
        ++_y;
    }

    answer.emplace_back(_x);
    answer.emplace_back(_y);

    /*bool _findanswer = false;
    int _lattice_cnt = brown + yellow;
    for (int i = 3; i <= _lattice_cnt; ++i)
    {
        for (int j = 3; j <= i; ++j)
        {
            int _B = (i * 2) + (2 * (j - 2));
            int _Y = (i - 2) * (j - 2);

            if (brown == _B && yellow == _Y)
            {
                _findanswer = true;
                answer.emplace_back(i);
                answer.emplace_back(j);
                break;
            }
        }

        if (_findanswer) break;
    }

    if (answer.empty()) return { 0, 0 };*/

    return answer;
}