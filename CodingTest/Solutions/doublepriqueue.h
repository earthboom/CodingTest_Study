#pragma once

#include "stdafx.h"

// 프로그래머스 고득점 Kit
// 힙 - 이중우선순위큐


vector<int> Doublepriorityqueue(vector<string> operations)
{
    vector<int> answer = { 0, 0 };
    vector<int> vecDPQ;

    for (string& _str : operations)
    {
        char key = _str[0];
        _str.erase(0, 2);
        int value = stoi(_str);

        if (key == 'D')
        {
            if (vecDPQ.size() != 0)
            {
                if (value == 1)
                    vecDPQ.erase(vecDPQ.begin());
                else
                    vecDPQ.pop_back();
            }            
        }
        else
            vecDPQ.emplace_back(value);

        sort(vecDPQ.begin(), vecDPQ.end(), greater<int>());
    }
    
    if(vecDPQ.size() == 1)
        answer = { vecDPQ[0], 0 };
    else if(vecDPQ.size() > 1)
        answer = { vecDPQ[0], vecDPQ[vecDPQ.size() - 1] };

    return answer;
}













vector<int> solution_doublepriqueue(vector<string> operations) 
{
    vector<int> answer = { 0, 0 };
    vector<int> vecDPQ;

    for (auto& _op : operations)
    {
        char _key = _op[0];
        _op.erase(0, 2);
        int _value = stoi(_op);

        if (_key == 'D')
        {
            if (vecDPQ.size() != 0)
            {
                if (_value == 1) // 최대값 삭제
                {
                    vecDPQ.erase(vecDPQ.begin());
                }
                else // 최소값 삭제
                {
                    vecDPQ.pop_back();
                }
            }
        }
        else
            vecDPQ.emplace_back(_value);

        sort(vecDPQ.begin(), vecDPQ.end(), greater<int>());
    }

    if (vecDPQ.size() == 1)
    {
        answer.emplace_back(vecDPQ[0]);
        answer.emplace_back(0);
    }
    else
    {
        answer.emplace_back(vecDPQ[0]);
        answer.emplace_back(vecDPQ[vecDPQ.size() - 1]);
    }

    return answer;
}