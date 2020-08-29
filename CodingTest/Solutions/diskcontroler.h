#pragma once

#include "stdafx.h"

class comparePQ
{
public:
    template<class T = vector<int>>
    bool operator() (T& _A, T& _B)
    {
        return _A[1] > _B[1];
    }
};
bool PQ_commpare(vector<int>& _vecA, vector<int>& _vecB)
{
    return (_vecA[0] < _vecB[0]);
}

int solution_diskcontroler(vector<vector<int>> jobs) {
    int answer = 0;

    priority_queue<vector<int>, vector<vector<int>>, comparePQ> PQ;

    sort(jobs.begin(), jobs.end());// PQ_commpare);

    int _time = jobs[0][0];
    auto iter = jobs.begin();
    while (iter != jobs.end() || !PQ.empty()) {
        while (iter != jobs.end() && (*iter)[0] <= _time) {
            PQ.push(*iter++);
        }

        if (!PQ.empty()) {
            _time += PQ.top()[1];
            answer += (_time - PQ.top()[0]);
            PQ.pop();
        }
        else {
            _time = (*iter)[0];
        }
    }

    answer /= jobs.size();
    return answer;
}