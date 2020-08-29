#pragma once

#include "stdafx.h"

int solution_startcount(vector<int> obstacle, int k)
{
    unordered_multiset<int> _answerList;
    for (auto& d : obstacle)
    {
        auto iter = _answerList.find(d - 1);
        if (_answerList.end() == iter)
        {
            _answerList.emplace(d);
            continue;
        }

        _answerList.erase(iter);
        _answerList.emplace(d);
    }

    int answer = _answerList.size();
    return answer;
}