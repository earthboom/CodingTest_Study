#pragma once

#include "stdafx.h"

int character_compression(string s)
{
	int answer = 0;

	int _iChar_length = s.length();

	int _iCycle = 0;
	if (_iChar_length > 1)
		_iCycle = _iChar_length / 2;
	else
		_iCycle = _iChar_length;

	string _strShotComp = s;
	int _iCurChar = 0;
	for (int i = 1; i <= _iCycle; ++i)
	{
		string _strNewComp = "";
		int _iRest = _iChar_length % i;
		for (int j = 0; j < _iChar_length;)
		{
			string _strTemp = s.substr(j, i);

			int _cnt = 1;
			for (int l = (j + i); l <= _iChar_length; (l += i))
			{
				if (!_strTemp.compare(s.substr(l, i)))
				{
					++_cnt;
					continue;
				}

				if (_cnt > 1)
					_strNewComp += to_string(_cnt);

				_strNewComp += _strTemp;

				break;
			}

			j += (_cnt * _strTemp.length());
		}

		if (_iRest > 0)
			_strNewComp += s.substr(_iChar_length - _iRest);

		if (_strShotComp.length() > _strNewComp.length())
			_strShotComp = _strNewComp;
	}

	answer = _strShotComp.length();
	return answer;
}