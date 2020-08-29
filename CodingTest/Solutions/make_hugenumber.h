#pragma once

#include "stdafx.h"

string solution_make_hugenumber(string number, int k)
{
    string answer = "";

    int _numsize = number.size() - k;
    int _pos = 0;
    int _index = 0;

    while (_numsize > 0)
    {
        char _max = '0';

        for (size_t i = _pos; i <= number.size() - _numsize; ++i)
        {
            if (number[i] > _max)
            {
                _max = number[i];
                _pos = i;
            }
        }

        ++_pos;
        --_numsize;
        answer += _max;
    }

    return answer;
}