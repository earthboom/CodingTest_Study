#pragma once

#include "stdafx.h"

vector<int> MockTest(vector<int> answers)
{
    vector<int> answer;
    vector<pair<vector<int>, int>> picktype = 
    {
        { {1, 2, 3, 4, 5}, 0 },
        { {2, 1, 2, 3, 2, 4, 2, 5}, 0 },
        { {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}, 0 }
    };

    for (int i = 0; i < answers.size(); ++i)
    {        
        for (int j = 0; j < 3; ++j)
        {
            int index = i - ((i / picktype[j].first.size()) * picktype[j].first.size());

            if (picktype[j].first[index] == answers[i])
                ++picktype[j].second;
        }
    }
    
    vector<pair<int, int>> align =
    {
        {1, picktype[0].second},
        {2, picktype[1].second},
        {3, picktype[2].second}
    };

    sort(align.begin(), align.end(), 
        [](pair<int, int>& _a, pair<int, int>& _b) {
            return _a.second > _b.second;
        });

    answer.emplace_back(align[0].first);

    if (align[0].second == align[1].second)
    {
        answer.emplace_back(align[1].first);

        if (align[1].second == align[2].second)
            answer.emplace_back(align[2].first);
    }
   
    return answer;
}
































vector<int> solution_Mockxam(vector<int> answers)
{
    vector<int> answer;
    vector<int> answer_cnt = { 0, 0, 0 };

    int  _first0 = 1;
    int  _second0 = 2, _second1 = 1;
    int  _third0 = 3;
    bool _bchange = false;
    for (size_t i = 0; i < answers.size(); ++i)
    {
        // 1
        if (answers[i] == (_first0++))
            ++answer_cnt[0];

        if (_first0 > 5)
            _first0 = 1;

        // 2
        if (((i + 1) % 2) != 0)
        {
            if (answers[i] == _second0)
                ++answer_cnt[1];
        }
        else
        {
            if (answers[i] == (_second1++))
                ++answer_cnt[1];

            if (_second1 == _second0)
                ++_second1;

            if (_second1 > 5)
                _second1 = 1;
        }

        // 3
        if (answers[i] == _third0)
            ++answer_cnt[2];

        if (((i + 1) % 2) == 0)
        {
            if (_bchange)
            {
                ++_third0;
                if (_third0 == 3)
                    ++_third0;

                if (_third0 == 5)
                    _bchange = false;
            }
            else
            {
                _third0 -= 2;

                if (_third0 == 1)
                    _bchange = true;
            }
        }
    }

    int _iBest = 0;
    for (auto& i : answer_cnt)
    {
        if (_iBest <= i)
            _iBest = i;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (_iBest == answer_cnt[i])
            answer.emplace_back(i + 1);
    }

    return answer;
}