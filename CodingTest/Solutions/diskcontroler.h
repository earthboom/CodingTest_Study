#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 힙 ( Heap )
// 디스크 컨트롤

//======================================================================================
//======================================================================================
class disk_cmp
{
public:
    bool operator()(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
};

int Disk_Controller_03(vector<vector<int>> job)
{
    int answer = 0;

    sort(job.begin(), job.end());

    priority_queue<vector<int>, vector<vector<int>>, disk_cmp> prique_jobs;
    int index = 0, current = 0;

    while (!prique_jobs.empty() || index != job.size())
    {
        while (index != job.size() && current >= job[index][0])
            prique_jobs.emplace(job[index++]);

        if (!prique_jobs.empty())
        {
            current += prique_jobs.top()[1];
            answer += (current - prique_jobs.top()[0]);
            prique_jobs.pop();
        }
        else
            current = job[index][0];
    }

    answer /= job.size();
    return answer;
}
//======================================================================================
//======================================================================================


//======================================================================================
//======================================================================================
class Compare_job
{
public:
    bool operator()(vector<int>& _a, vector<int>& _b)
    {
        return _a[1] > _b[1];
    }
};

int Disk_Controller(vector<vector<int>> job)
{
    int answer = 0;
    int current = 0, index = 0;

    priority_queue<vector<int>, vector<vector<int>>, Compare_job> pqbjobs;

    sort(job.begin(), job.end());

    while (index != job.size() || !pqbjobs.empty())
    {
        while (index != job.size() && job[index][0] <= current)
            pqbjobs.emplace(job[index++]);

        if (!pqbjobs.empty())
        {
            current += pqbjobs.top()[1];
            answer += (current - pqbjobs.top()[0]);
            pqbjobs.pop();
        }
        else
            current = job[index][0];
    }

    answer /= job.size();
    return answer;
}
//======================================================================================
//======================================================================================


//======================================================================================
//======================================================================================
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
//======================================================================================
//======================================================================================