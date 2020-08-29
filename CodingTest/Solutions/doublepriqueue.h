#pragma once

#include "stdafx.h"

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
                if (_value == 1) // �ִ밪 ����
                {
                    vecDPQ.erase(vecDPQ.begin());
                }
                else // �ּҰ� ����
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