#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 2

// 완전탐색
// 소수 찾기

//======================================================================================
//======================================================================================
int Find_PrimeNumber_03(string numbers)
{
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<int>());

    vector<char> vecNum;
    for (char& n : numbers)
        vecNum.emplace_back(n);
   
    int max = stoi(numbers);
        
    vector<bool> eratos(max + 1, true);
    for (int i = 2; i * i <= max; ++i)
    {
        if (eratos[i])
        {
            for (int j = i * i; j <= max; j += i)
                eratos[j] = false;
        }
    }

    for (int i = 2; i < eratos.size(); ++i)
    {
        if (eratos[i] == false)
            continue;

        string num = to_string(i);

        for (char& n : vecNum)
        {
            auto iter = find(num.begin(), num.end(), n);
            if (iter != num.end())
                num.erase(iter);
            
            if (num.size() == 0)
            {
                ++answer;
                break;
            }
        }
    }

    return answer;
}
//======================================================================================
//======================================================================================




//======================================================================================
//======================================================================================
int Find_PrimeNumber(string numbers)
{
    int answer = 0;

    vector<char> vecNumber;
    for (int i = 0; i < numbers.size(); ++i)
        vecNumber.emplace_back(numbers[i]);
    
    vector<int> all_numbers;
    int cnt = 0;
    for (int i = 1; i < numbers.size() + 1; ++i)
    {
        do
        {
            string strTemp = "";
            int digits = 0;

            for (char& n : vecNumber)
            {
                strTemp += n;
                if (++digits == i)
                    break;
            }

            all_numbers.emplace_back(stoi(strTemp));
        } while (next_permutation(vecNumber.begin(), vecNumber.end()));
    }

    sort(all_numbers.begin(), all_numbers.end());
    all_numbers.erase(unique(all_numbers.begin(), all_numbers.end()), all_numbers.end());

    auto primecheck = [](int num) ->bool {
        if (num <= 1)
            return false;

        int sqr = sqrt(num);
        for (int i = 2; i <= sqr; ++i)
        {
            if (num % i == 0)
                return false;
        }

        return true;
    };

    for (int& an : all_numbers)
    {
        if (primecheck(an))
            ++answer;
    }

    return answer;
}
//======================================================================================
//======================================================================================



//======================================================================================
//======================================================================================
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
//======================================================================================
//======================================================================================