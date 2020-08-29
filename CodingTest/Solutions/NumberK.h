#pragma once

#include "stdafx.h"

vector<int> solution_NumberK(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> queSort;
    for (size_t i = 0; i < commands.size(); ++i)
    {
        vector<int> _command = commands[i];

        for (int j = _command[0] - 1; j < _command[1]; ++j)
        {
            queSort.push(array[j]);
        }

        for (int j = 0; j < _command[2] - 1; ++j)
            queSort.pop();

        answer.emplace_back(queSort.top());

        while (!queSort.empty())
            queSort.pop();
    }

    return answer;
}