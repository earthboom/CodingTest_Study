#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 2

// 스택 / 큐 ( stack / queue )
// 프린터

//======================================================================================
//======================================================================================
int Printer_03(vector<int> priorities, int location)
{
    int answer = 0;

    queue<pair<int, int>> lineup;
    priority_queue<int, vector<int>> pq_sort;
    for (int i = 0; i < priorities.size(); ++i)
    {
        lineup.emplace(make_pair(i, priorities[i]));
        pq_sort.emplace(priorities[i]);
    }

    while (answer != priorities.size())
    {
        int order = lineup.front().first;
        int importance = lineup.front().second;
        lineup.pop();

        if (importance == pq_sort.top())
        {
            ++answer;
            pq_sort.pop();

            if (order == location)
                break;
        }
        else
            lineup.emplace(make_pair(order, importance));
    }

    return answer;
}
//======================================================================================
//======================================================================================


//======================================================================================
//======================================================================================
int Printer(vector<int> priorities, int location)
{
    int answer = 0;

    priority_queue<int> pq_sort;
    queue<pair<int, int>> que_priorities;

    for (int i = 0; i < priorities.size(); ++i)
    {
        pq_sort.push(priorities[i]);
        que_priorities.push(make_pair(i, priorities[i]));
    }

    for (int i = 0; i < priorities.size(); ++i)
    {
        int first = que_priorities.front().first;
        int second = que_priorities.front().second;
        que_priorities.pop();

        if (second == pq_sort.top())
        {
            pq_sort.pop();
            ++answer;

            if (location == first)
                break;
        }
        else
            que_priorities.push(make_pair(first, second));
    }

    return answer;
}
//======================================================================================
//======================================================================================


//======================================================================================
//======================================================================================
int solution_print(vector<int> priorities, int location)
{
    int answer = 0;

    queue<pair<int, int>> queBase;
    priority_queue<int> queSort;

    for (size_t i = 0; i < priorities.size(); ++i)
    {
        queBase.push(make_pair(i, priorities[i]));
        queSort.push(priorities[i]);
    }

    while (!queBase.empty())
    {
        int _iFirst = queBase.front().first;
        int _iSecond = queBase.front().second;
        queBase.pop();

        if (_iSecond == queSort.top())
        {
            queSort.pop();
            ++answer;

            if (_iFirst == location)
                break;
        }
        else
            queBase.push(make_pair(_iFirst, _iSecond));
    }

    return answer;
}
//======================================================================================
//======================================================================================