#pragma once

#include "stdafx.h"

// 프로그래머스 고득점 Kit
// 정렬 - 가장 큰 수

bool compare_BN(int& _a, int& _b)
{
    string s_a = to_string(_a), s_b = to_string(_b);

    return s_a + s_b > s_b + s_a;
}

string solution_BiggestNumber(vector<int> numbers)
{
    string answer = "";

    std::sort(numbers.begin(), numbers.end(), compare_BN);

    if (numbers.at(0) == 0)
        return "0";

    for (auto& _s : numbers)
        answer += std::to_string(_s);

    return answer;
}



//bool compare_BiggestNumber(string& a, string& b)
//{
//    return a + b > b + a;
//}
//
//string solution_BiggestNumber(vector<int> numbers) 
//{
//    string answer = "";
//
//    vector<string> vecStrnum;
//
//    for (auto& n : numbers)
//        vecStrnum.emplace_back(to_string(n));
//
//    sort(vecStrnum.begin(), vecStrnum.end(), compare_BiggestNumber);
//
//    if (vecStrnum.at(0) == "0")
//        return "0";
//
//    for (auto& s : vecStrnum)
//        answer += s;
//
//    return answer;
//}