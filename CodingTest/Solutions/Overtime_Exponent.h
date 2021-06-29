#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 연습문제
// 야근 지수

//======================================================================================
//======================================================================================
long long Overtime_Exponent(int n, vector<int> works) 
{
    long long answer = 0;

    priority_queue<int> que(works.begin(), works.end());

    for (int i = 0; i < n; ++i)
    {
        if (que.top() > 0)
        {
            int tmp = que.top();
            que.pop();
            que.emplace(tmp - 1);
        }
    }

    while (!que.empty())
    {
        answer += ((long long)que.top() * (long long)que.top());
        que.pop();
    }


    //sort(works.begin(), works.end(), greater<int>());

    //while (n > 0)
    //{
    //    int cnt = 0;
    //    int dif = n - works.size();
    //    if (dif >= 0)
    //        cnt = works.size();
    //    else
    //        cnt = n;

    //    for (int i = 0; i < cnt; ++i)
    //    {
    //        works[i] -= 1;
    //        if (works[i] < 0)
    //            works[i] = 0;
    //    }

    //    n -= works.size();
    //}

    //for (int& w : works)
    //    answer += (w * w);

    return answer;
}
//======================================================================================
//======================================================================================