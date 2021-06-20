#pragma once

#include "stdafx.h"

// ���α׷��ӽ� ����� Kit
// ���� - K ��° ����

//priority_queue �����̳�
//
//- �켱���� ť�� ������ �����̳�.
//- vector, dequeue�� �ٿ��� ����� ����, list�� �Ұ���.
//- vector ������� ����
//- ���� ������ default�� ��������(less<>)
//- <queue>����� ����.
//
//- �⺻ ������ ���� : priority_queue<[������ Ÿ��] > [���� �̸�];
//
//- ���� �����̳� ���� : priority_queue<[������ Ÿ��], [�����̳� Ÿ��]> [���� �̸�];
//
//- ���� ���� ���� : priority_queue<[������ Ÿ��], [�����̳� Ÿ��], [���ı���]> [���� �̸�];


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