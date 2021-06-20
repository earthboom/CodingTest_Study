#pragma once

#include "stdafx.h"

bool compare(pair<string, int> _a, pair<string, int> _b)
{
	return _a.second > _b.second;
}

string Strugacarro_season(vector<int> A, int N)
{
	if ((N < 8) && (N > 200))
		return nullptr;

	if ((N % 4) != 0)
		return nullptr;

	int _iDiv = N / 4, _iCnt = 0, _iss = 0;
	vector<pair<string, int>> vecSeason = { {"WINTER", 0}, {"SPRING", 0}, {"SUMMER", 0}, {"AUTUMN", 0} };
	for (int i = 0; i < vecSeason.size(); ++i)
	{
		for (int j = ((i * _iDiv) + 1); j < ((i + 1) * _iDiv); ++j)
			vecSeason[i].second += abs(A[j - 1] - A[j]);
	}

	sort(vecSeason.begin(), vecSeason.end(), compare);

	return vecSeason[0].first;
}