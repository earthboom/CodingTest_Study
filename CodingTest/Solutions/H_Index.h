#pragma once

#include "stdafx.h"

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