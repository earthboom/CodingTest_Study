#pragma once

#include "stdafx.h"

vector<int> solution_stock(vector<int> prices)
{
    vector<int> answer;

    int _imaintain = 0;
    for (size_t i = 0; i < prices.size(); ++i)
    {
        for (size_t j = i + 1; j < prices.size(); ++j)
        {
            ++_imaintain;

            if (prices[i] > prices[j])
            {
                break;
            }
        }

        answer.emplace_back(_imaintain);
        _imaintain = 0;
    }

    return answer;
}