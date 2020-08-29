#pragma once

#include "stdafx.h"

bool compare_BiggestNumber(string& a, string& b)
{
    return a + b > b + a;
}

string solution_BiggestNumber(vector<int> numbers) 
{
    string answer = "";

    vector<string> vecStrnum;

    for (auto& n : numbers)
        vecStrnum.emplace_back(to_string(n));

    sort(vecStrnum.begin(), vecStrnum.end(), compare_BiggestNumber);

    if (vecStrnum.at(0) == "0")
        return "0";

    for (auto& s : vecStrnum)
        answer += s;

    return answer;
}