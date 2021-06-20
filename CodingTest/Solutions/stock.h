#pragma once

#include "stdafx.h"

// 프로그래머스 고득점 Kit
// 스택 / 큐 - 주식가격 (Lv2)

vector<int> stock_price(vector<int> prices)
{
    vector<int> answer;

    int iCnt = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
        for (int j = i + 1; j < prices.size(); ++j)
        {
            ++iCnt;

            if (prices[i] > prices[j])
                break;
        }

        answer.emplace_back(iCnt);
        iCnt = 0;
    }

    return answer;
}

















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