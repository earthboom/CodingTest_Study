#pragma once

#include "stdafx.h"

int solution_ramenFactory(int stock, vector<int> dates, vector<int> supplies, int k) 
{
    int answer = 0;

    priority_queue<int, vector<int>, less<int>> queFlour;

    int j = 0;
    for (int i = 0; i < k; ++i)
    {
        if (dates[j] == i)
        {
            queFlour.push(supplies[j]);

            if (j < int(supplies.size() - 1))
            {
                ++j;
            }
        }

        if (stock <= 0)
        {
            stock = queFlour.top();
            queFlour.pop();
            ++answer;
        }

        --stock;
    }

    return answer;
}