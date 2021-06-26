#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 힙 ( Heap )
// 이중우선순위큐

//======================================================================================
//======================================================================================
vector<int> Doublepriorityqueue_03(vector<string> operations)
{
    vector<int> answer = { 0, 0 };
    deque<int> deque_oper;

    for (string& o : operations)
    {
        char key = o[0];
        o.erase(0, 2);
        int value = stoi(o);

        if (key == 'D')
        {
            if (deque_oper.size() > 0)
            {
                sort(deque_oper.begin(), deque_oper.end(), greater<int>());
                if (value == 1)
                    deque_oper.pop_front();
                else
                    deque_oper.pop_back();
            }            
        }
        else
            deque_oper.push_back(value);
    }

    if (deque_oper.size() != 0)
    {
        if (deque_oper.size() == 1)
            answer.emplace_back(0);

        sort(deque_oper.begin(), deque_oper.end(), greater<int>());
        answer[0] = deque_oper.front();
        answer[1] = deque_oper.back();
    }    

    return answer;
}
//======================================================================================
//======================================================================================



//======================================================================================
//======================================================================================
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
//======================================================================================
//======================================================================================



//======================================================================================
//======================================================================================
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
//======================================================================================
//======================================================================================