#pragma once

#include "stdafx.h"

int solution_boat(vector<int> people, int limit)
{
    if (people.size() == 1)  return 1;

    int answer = 0;

    sort(people.begin(), people.end(), less<int>());

    int _F = 0, _B = people.size() - 1;
    while (_F < _B)
    {
        if (people[_F] + people[_B] > limit)
        {
            ++answer;
            --_B;
        }
        else
        {
            ++answer;
            ++_F;
            --_B;
        }

        if (_F == _B) ++answer;
    };

    return answer;
}