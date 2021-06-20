#pragma once

#include "stdafx.h"

string RecommandID(string new_id) 
{
    string answer = "";

    for (int i = 0; i < new_id.size(); ++i) 
    {
        if (isupper(new_id[i]))
            new_id[i] = tolower(new_id[i]);
    }

    for (int i = 0; i < new_id.size();)
    {
        int iAsc = new_id[i];
        
        bool bAllow = false;
        if ((iAsc >= 97 && iAsc <= 122) || 
            (iAsc >= 48 && iAsc <= 57) ||
            iAsc == 45 || iAsc == 46 || iAsc == 95)
            bAllow = true;

        if (!bAllow)
            new_id.erase(i, 1);
        else
            ++i;
    }
    
    for (int i = 0; i < new_id.size();)
    {
        int iAsc = new_id[i];
        
        if (iAsc != 46)
        {
            ++i;
            continue;
        }

        int iCnt = 0;
        int iRest = new_id.size() - i;
        for (int j = i + 1; j < i + 1 + iRest; ++j)
        {
            iAsc = new_id[j];
            if (iAsc != 46) break;

            ++iCnt;
        }

        if (iCnt != 0)
            new_id.erase(i + 1, iCnt);

         ++i;
    }
    
    
    if (new_id[0] == 46)
        new_id.erase(0, 1);

    if (new_id.size() != 0)
    {
        if (new_id[new_id.size() - 1] == 46)
            new_id.erase(new_id.size() - 1, 1);
    }    

    if (new_id.empty())
        new_id = "a";

    if (new_id.size() >= 16)
    {
        new_id.erase(15);

        if (new_id[new_id.size() - 1] == 46)
            new_id.erase(new_id.size() - 1);
    }

    if (new_id.size() <= 2)
    {
        while (new_id.size() < 3)
        {
            new_id += new_id[new_id.size() - 1];
        }
    }

    answer = new_id;

    return answer;
}