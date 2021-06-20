#pragma once

#include "stdafx.h"


string SearchCourse(const vector<string>& _orders, const string& _strClinetOrder, const int& _iMenuCnt, int _iCur, map<string, int>& _mapOrder)
{
    string strCombi = "";
    for (int i = 0; i < _strClinetOrder.size(); ++i)
    {
        strCombi += _strClinetOrder.at(i);

        for (int j = i + 1; j < _strClinetOrder.size(); ++j)
        {
            if (!strCombi.find(_strClinetOrder[j])) continue;

            strCombi += _strClinetOrder[j];

            if (strCombi.size() >= _iMenuCnt)
            {
                bool bCreate = false;
                for (int k = 0; k < _orders.size(); ++k)
                {
                    if (k == _iCur) continue;
                    
                    if (strCombi.size() == _orders[k].size())
                    {
                        if (strCombi == _orders[k])
                        {
                            if (_mapOrder.find(strCombi) == _mapOrder.end())
                            {
                                _mapOrder.emplace(make_pair(strCombi, 2));
                                bCreate = true;
                            }
                            else
                            {
                                if (bCreate)
                                    ++_mapOrder.find(strCombi)->second;
                            }
                        }
                    }
                    else
                    {
                        string _strCO2 = _orders[k];

                        int _iFindCnt = 0;
                        for (int l = 0; l < strCombi.size(); ++l)
                        {
                            if (_strCO2.find(strCombi.at(l)) != string::npos)
                                ++_iFindCnt;

                            if (_iFindCnt == _iMenuCnt)
                            {
                                if (_mapOrder.find(strCombi) == _mapOrder.end())
                                {
                                    _mapOrder.emplace(make_pair(strCombi, 2));
                                    bCreate = true;
                                }
                                else
                                {
                                    if (bCreate)
                                        ++_mapOrder.find(strCombi)->second;
                                }
                            }
                        }
                    }
                }
                strCombi.erase(_iMenuCnt - 1);
            }           
        }

        strCombi = "";
    }

    return strCombi;
}

bool cmp(const pair<string, int>& _a, const pair<string, int>& _b)
{
    return _a.second > _b.second;
}

vector<string> CourseFood(vector<string> orders, vector<int> course) {
    vector<string> answer;

    map<string, int> mapOrders;
    for (int i = 0; i < course.size(); ++i)
    {
        int iMenuCnt = course[i];
               
        for (int j = 0; j < orders.size(); ++j)
        {
            SearchCourse(orders, orders[j], iMenuCnt, j, mapOrders);
        }
    }

    for (int _iNum : course)
    {
        vector<pair<string, int>> _vecorders;
        for (map<string, int>::iterator iter = mapOrders.begin(); iter != mapOrders.end(); ++iter)
        {
            if (_iNum != iter->first.size())
                continue;

            _vecorders.emplace_back(iter->first, iter->second);
        }

        sort(_vecorders.begin(), _vecorders.end(), cmp);

        for (int i = 0; i < _vecorders.size(); ++i)
        {
            if (_vecorders[0].second == _vecorders[i].second)
                answer.emplace_back(_vecorders[i].first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}