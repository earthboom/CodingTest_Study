#pragma once

#include "stdafx.h"

// ���α׷��ӽ� ����� Kit
// �ؽ� - ��ȭ��ȣ ���

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