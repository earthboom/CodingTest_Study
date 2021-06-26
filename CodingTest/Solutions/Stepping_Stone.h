#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 4

// 이분 탐색 (Binary Search)
// 징검다리

int Stepping_ston(int distance, vector<int> rocks, int n)
{
	int answer = 0;

    sort(rocks.begin(), rocks.end());

    int left = 1, right = distance;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if ([](vector<int>& _rocks, int& _m, int& _dist)->int {
            int cnt=0, prev=0;
            
            for (int i = 0; i < _rocks.size(); ++i)
            {
                if(_rocks[i] - prev < _m)
                    ++cnt;
                else
                    prev = _rocks[i];
            }
            
            if (_dist - prev < _m)
                ++cnt;

            return cnt;
        }(rocks, mid, distance) > n)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            
            if (mid > answer)
                answer = mid;
        }
    }

	return answer;
}














int Stepping_ston_EX(int distance, vector<int> rocks, int n) {
    int answer = 0;

    rocks.emplace_back(0);
    rocks.emplace_back(distance);

    sort(rocks.begin(), rocks.end());

    int l = 1, h = distance, m = 0, v = 0, cnt = 0;
    while (l != h)
    {
        m = (l + h + 1) / 2;
        cnt = 0;

        for (int i = 0; i < rocks.size() - 1; ++i)
        {
            v = rocks[i + 1] - rocks[i];

            while (cnt < n
                && v < m
                && i < rocks.size() - 2)
            {
                ++i;
                v += rocks[i + 1] - rocks[i];
                ++cnt;
            }

            if (v < m)
            {
                cnt = n + 1;
                break;
            }
        }

        if (cnt > n)
            h = m - 1;
        else
            l = m;
    }

    answer = l;

    return answer;
}