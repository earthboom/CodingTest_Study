#pragma once

#include "stdafx.h"

// ���α׷��ӽ� ����� Kit
// �ؽ� - ����

typedef unordered_map<string, int> KindMap;

int Camouflage(vector<vector<string>> clothes)
{
	int answer = 1;

	KindMap mapKindClothe;
	for (vector<string>& c : clothes)
	{
		if (mapKindClothe.find(c[1]) == mapKindClothe.end())
			mapKindClothe.emplace(KindMap::value_type(c[1], 1));
		else
			++mapKindClothe[c[1]];
	}

	for (auto& m : mapKindClothe)
		answer *= (m.second + 1);

	answer -= 1;

	return answer;
}