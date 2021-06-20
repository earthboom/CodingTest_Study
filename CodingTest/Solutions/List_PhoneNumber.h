#pragma once

#include "stdafx.h"

// 프로그래머스 고득점 Kit
// 해시 - 전화번호 목록

bool List_PhoneNumber(vector<string> phone_book)
{
	sort(phone_book.begin(), phone_book.end());
	for (int i=0; i<phone_book.size()-1; ++i)
	{
		if (phone_book[i+1].find(phone_book[i]) == 0)
		{
			return false;
		}
	}

	return true;
}