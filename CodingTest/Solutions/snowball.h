#pragma once

#include "stdafx.h"

vector<int> solution_snowball(vector<int> snowballs)
{
    bool _bCrash = true;
    while (_bCrash)
    {
        _bCrash = false;
        int _iSize = snowballs.size() - 1;
        for (int i = 0; i < _iSize; ++i)
        {
            if ((snowballs[i] > 0) && (snowballs[i + 1] < 0))
            {
                if ((snowballs[i] + snowballs[i + 1]) == 0)
                    snowballs.erase((snowballs.begin() + i), (snowballs.begin() + i + 2));
                else if ((snowballs[i] + snowballs[i + 1]) > 0)
                    snowballs.erase(snowballs.begin() + (i + 1));
                else
                    snowballs.erase(snowballs.begin() + i);

                _bCrash = true;
                break;
            }
        }
    }

    return snowballs;
}