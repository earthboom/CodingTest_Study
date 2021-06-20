#pragma once

#include "stdafx.h"

// 프로그래머스 고득점 Kit
// 정렬 - K 번째 선수

//priority_queue 컨테이너
//
//- 우선순위 큐를 구현한 컨테이너.
//- vector, dequeue를 붙여서 사용이 가능, list는 불가능.
//- vector 기반으로 설정
//- 정렬 기준의 default는 내림차순(less<>)
//- <queue>헤더에 있음.
//
//- 기본 생성자 형식 : priority_queue<[데이터 타입] > [변수 이름];
//
//- 내부 컨테이너 변경 : priority_queue<[데이터 타입], [컨테이너 타입]> [변수 이름];
//
//- 정렬 기준 변경 : priority_queue<[데이터 타입], [컨테이너 타입], [정렬기준]> [변수 이름];


vector<int> solution_NumberK(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> P_que_sort;
    for (size_t i = 0; i < commands.size(); ++i)
    {
        vector<int> _cmd = commands[i];

        for (int j = _cmd[0] - 1; j < _cmd[1]; ++j)
            P_que_sort.push(array[j]);

        for (int j = 0; j < _cmd[2] - 1; ++j)
            P_que_sort.pop();

        answer.emplace_back(P_que_sort.top());

        while (!P_que_sort.empty())
            P_que_sort.pop();
    }    

    return answer;
}