#pragma once

#include "stdafx.h"

bool Check_PrimerNumber(int _num)
{
    if (_num <= 1)
        return false;

    for (int i = 2; i <= sqrt(_num); ++i)
    {
        if ((_num % i) == 0)
            return false;
    }

    return true;
}

int solution_primeNumber(string numbers)
{
    int answer = 0;

    vector<char> vecNum;
    for (auto& c : numbers)
    {
        vecNum.emplace_back(c);
    }

    sort(vecNum.begin(), vecNum.end(), less<int>());

    vector<int> vecPrime;
    string strNum = "";
    int _iCount = vecNum.size() + 1;
    for (int i = 1; i < _iCount; ++i)
    {
        do
        {
            int _iCnt = 0;
            strNum = "";
            for (auto& c : vecNum)
            {
                strNum += c;
                if (++_iCnt == i)
                    break;
            }

            vecPrime.emplace_back(stoi(strNum));
        } while (next_permutation(vecNum.begin(), vecNum.end()));
    }

    sort(vecPrime.begin(), vecPrime.end(), less<int>());
    vecPrime.erase(unique(vecPrime.begin(), vecPrime.end()), vecPrime.end());

    for (auto& i : vecPrime)
    {
        if (Check_PrimerNumber(i))
            ++answer;
    }

    return answer;
}