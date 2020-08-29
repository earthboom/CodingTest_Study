#pragma once

#include "stdafx.h"

int solution_pipecut(string arrangement) 
{
    int answer = 0;

    int _istrNum = arrangement.size();

    int _ilineCnt = 0;
    for (int i = 0; i < _istrNum; ++i)
    {
        if (arrangement[i] == '(')
        {
            if ((i + 1) < _istrNum && arrangement[i + 1] == ')')
            {
                answer += _ilineCnt;
                ++i;
            }
            else
            {
                ++_ilineCnt;
            }
        }
        else if (arrangement[i] == ')')
        {
            --_ilineCnt;
            ++answer;
        }
    }

    return answer;
}