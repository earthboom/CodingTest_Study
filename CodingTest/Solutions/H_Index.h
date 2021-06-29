#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 2

// 정렬
// H Index

//======================================================================================
//======================================================================================
int H_Index_03(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    int refs = 0;
    for (int i = 1; i <= citations.size(); ++i)
    {
        refs = citations[i - 1];

        if (i > refs)
        {
            answer = i - 1;
            break;
        }

        if (i == citations.size())
            answer = i;
    }
 
    return answer;
}
//======================================================================================
//======================================================================================



//======================================================================================
//======================================================================================
int solution_H_Index_02(vector<int> citations) 
{
    int answer = 0;
   
    sort(citations.begin(), citations.end(), greater<int>());

    int _ref = 0;
    for (int i = 1; i <= citations.size(); ++i)
    {
        _ref = citations[i - 1];

        if (i > _ref)
        {
            answer = i - 1;
            break;
        }

        if (i == citations.size())
            answer = i;
    }

    return answer;
}
//======================================================================================
//======================================================================================



//======================================================================================
//======================================================================================
int solution_H_Index(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), less<int>());

    int _iQuotation_O = 0;
    for (int i = 0; i < citations[citations.size() - 1]; ++i)
    {
        for (size_t j = 0; j < citations.size(); ++j)
        {
            if (i <= citations[j])
                ++_iQuotation_O;
        }

        if (i <= _iQuotation_O)
            answer = i;

        if (i > _iQuotation_O)
            break;

        _iQuotation_O = 0;
    }

    return answer;
}
//======================================================================================
//======================================================================================