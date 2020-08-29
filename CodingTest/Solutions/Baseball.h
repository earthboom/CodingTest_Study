#pragma once

#include "stdafx.h"

vector<int> PositionalNumber(int& _num)
{
    vector<int> _vec;

    int hundred = int(_num / 100);
    int ten = int((_num / 10) % 10);
    int one = int(_num % 10);

    _vec.emplace_back(hundred);
    _vec.emplace_back(ten);
    _vec.emplace_back(one);

    return _vec;
}

int solution_Baseball(vector<vector<int>> baseball)
{
    int answer = 0;

    for (int i = 123; i < 988; ++i)
    {
        int _exactCount = 0;
        vector<int> _vNum = PositionalNumber(i);

        if (_vNum[0] == _vNum[1] || _vNum[0] == _vNum[2] || _vNum[1] == _vNum[2]
            || !_vNum[0] || !_vNum[1] || !_vNum[2]) continue;

        for (auto& _inning : baseball)
        {
            vector<int> _vSwing;
            int _strike_count = 0;
            int _out_count = 0;

            _vSwing = PositionalNumber(_inning[0]);

            for (int j = 0; j < 3; ++j)
            {
                if (_vNum[j] == _vSwing[j]) ++_strike_count;
                if (_vNum[j] == _vSwing[(j + 1) % 3] || _vNum[j] == _vSwing[(j + 2) % 3]) ++_out_count;
            }

            if (_inning[1] == _strike_count && _inning[2] == _out_count) ++_exactCount;
        }

        if (_exactCount == baseball.size())
            ++answer;

    }

    return answer;
}