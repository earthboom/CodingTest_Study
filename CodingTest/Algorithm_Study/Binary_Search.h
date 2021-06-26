#pragma once

#include "stdafx.h""

// ÀÌÁø Å½»ö (Binary Search)

void Binary_search_02(int target, vector<int> array)
{
	int k = 0;
	int size = array.size();

	for (int i = size / 2; i >= 1; i /= 2)
	{
		while (k + i < size && array[k + i] <= target)
		{
			k += i;
		}
	}

	if (array[k] == target)
	{

	}
}
