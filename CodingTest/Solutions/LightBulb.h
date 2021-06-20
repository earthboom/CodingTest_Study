#pragma once

#include "stdafx.h"

int LightBulb(vector<int> A, int N)
{
	int answer = 0;
	bool _bCondition = false;
	
	vector<bool> vecButton;
	vecButton.resize(N);

	for (const auto& i : A)
	{
		vecButton[i-1] = true;

		if (i == 1)
			_bCondition = true;

		if (!_bCondition) continue;

		bool _bLight = false;
		for (const bool& _b : vecButton)
		{
			if (_bLight && _b)
			{
				_bLight = false;
				break;
			}

			if (_b == false)
				_bLight = true;
		}

		if (_bLight)
			++answer;
	}

	return answer + 1;
}
