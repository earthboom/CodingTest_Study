#pragma once

#include "stdafx.h"

int solution_joystick(string name)
{
    int answer = 0;

    int _check = name.size();
    vector<pair<char, bool>> vecName;
    for (auto& c : name)
    {
        if (c == 'A')
        {
            --_check;
            vecName.emplace_back(make_pair(c, true));
        }
        else
            vecName.emplace_back(make_pair(c, false));
    }

    int _index = 0;
    do
    {
        int _front = 1, _back = 1;

        if (vecName[_index].first != 'A')
        {
            if (vecName[_index].first <= 'N')
                answer += (vecName[_index].first - 'A');
            else
                answer += (('Z' - vecName[_index].first) + 1);

            vecName[_index].second = true;
            --_check;
        }

        if (_check > 0)
        {
            while (true)
            {
                int _F = _index + _front;
                int _B = _index - _back;

                if (_F >= vecName.size())
                    _F -= vecName.size();

                if (_B < 0)
                    _B = (vecName.size() + _B);

                if ((!vecName[_F].second && vecName[_F].first != 'A')
                    && (!vecName[_B].second && vecName[_B].first != 'A'))
                    break;

                if (vecName[_F].second || vecName[_F].first == 'A')
                    ++_front;

                if (vecName[_B].second || vecName[_B].first == 'A')
                    ++_back;
            }

            if (_front <= _back)
            {
                _index += _front;
                answer += _front;
            }
            else
            {
                _index -= _back;
                answer += _back;
            }

            if (_index < 0)
                _index = (vecName.size() + _index);
        }
    } while (_check > 0);

    return answer;
}