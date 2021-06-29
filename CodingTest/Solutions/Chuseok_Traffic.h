#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 2018 KAKAO Blind Recruitment
// 추석 트래픽

// ex 2016-09-15 hh:mm:ss.sss 0.11s

//======================================================================================
//======================================================================================
typedef struct timeData
{
    short years;
    short month;
    short days;

    short hour;
    short minute;
    
    double second;
    double processtime;
}TIME_DATA;

int Chuseok_Traffic(vector<string> lines) 
{
    int answer = 0;

    vector<int> vecProcess, vecEnd;

    for (string& str : lines)
    {
        string sh, sm, ss, sms;
        int ih, im, is, process;

        str.pop_back(); // s제거
        
        sh = str.substr(11, 2);
        sm = str.substr(14, 2);
        ss = str.substr(17, 2);
        sms = str.substr(20, 3);

        process = stof(str.substr(24, 5)) * 1000;
        ih = stoi(sh) * 3600 * 1000;
        im = stoi(sm) * 60 * 1000;
        is = stoi(ss) * 1000 + stoi(sms);

        vecProcess.emplace_back(process);
        vecEnd.emplace_back(ih + im + is);
    }

    int l_size = lines.size();
    int next_start = 0, range = 0;
    for (int i = 0; i < l_size; ++i)
    {
        int cnt = 1;
        range = vecEnd[i] + 1000;

        for (int j = i + 1; j < l_size; ++j)
        {
            next_start = vecEnd[j] - vecProcess[j] + 1;
            if (next_start < range)
            {
                ++cnt;
                continue;
            }
        }

        if(answer < cnt)
            answer = cnt;
    }

    return answer;
}
//======================================================================================
//======================================================================================