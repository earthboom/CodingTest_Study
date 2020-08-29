#pragma once

#include "stdafx.h"

string barcet_recursive(string _p)
{
	if (_p.empty())
		return _p;

	string u, v;
	int _iLength = _p.length();

	int _iCnt = 1;
	u = _p[0];
	for (int i = 1; i < _iLength; ++i)
	{
		if (_iCnt > 0)
		{
			u += _p[i];
			if (u[0] == u[i])
				++_iCnt;
			else
				--_iCnt;
		}
		else
		{
			v += _p[i];
		}
	}

	if (u[0] == '(')
	{
		return u + barcet_recursive(v);
	}
	else
	{
		for (auto& _char : u)
			_char = _char == '(' ? ')' : '(';

		return "(" + barcet_recursive(v) + ")" + u.substr(1, u.length() - 2);
	}
}

string barcet_arrange(string p)
{
	string answer = barcet_recursive(p);

	return answer;
}