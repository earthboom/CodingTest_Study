#pragma once

#include "stdafx.h"

int solution_workout_clothes(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    for (size_t i = 0; i < lost.size(); ++i)
    {
        for (size_t j = 0; j < reserve.size(); ++j)
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i--);
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }

    if (lost.size() == 0) return answer;
    answer = n - lost.size();

    int _cnt = 0;
    for (size_t i = 0; i < reserve.size(); ++i)
    {
        for (size_t j = 0; j < lost.size(); ++j)
        {
            if ((reserve[i] - 1) == lost[j] || (reserve[i] + 1) == lost[j])
            {
                ++_cnt;
                lost.erase(lost.begin() + j);
                break;
            }
        }

        if (n == (_cnt + answer))
            break;
    }

    answer += _cnt;

    return answer;
}