#pragma once

#include "stdafx.h"

// ���α׷��ӽ� ����� Kit
// �ؽ� - �������� ���� ����

typedef unordered_map<string, int> URMAP;

string Unfinished_Runner(vector<string> participant, vector<string> completion)
{
	string answer = "";

	URMAP arrange_map;
	for (auto& s : participant)
	{
		URMAP::iterator iter = arrange_map.find(s);
		if (iter == arrange_map.end())
			arrange_map.emplace(URMAP::value_type(s, 1));
		else
			++iter->second;
	}

	for (auto& s : completion)
	{
		URMAP::iterator iter = arrange_map.find(s);
		if (iter != arrange_map.end())
		{
			if (iter->second > 0)
				--iter->second;

			if(iter->second <= 0)
				arrange_map.erase(iter->first);
		}
	}

	answer = arrange_map.begin()->first;

	return answer;
}
