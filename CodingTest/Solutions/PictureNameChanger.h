#pragma once

#include "stdafx.h"

typedef struct sData
{
	string city;
	string extention;
	string time;
	string count;
}DATA;

typedef struct sTime
{
	int year;
	int month;
	int day;

	int hour;
	int min;
	int sec;
}TIME;

bool compareTime(const string& _a, const string& _b)
{
	return _a < _b;
}

string PictureNameChanger(string S)
{
	string answer = "";

	map<string, vector<string>> mapCitySeq;
	vector<DATA> vecOrganize;
	
	while (!S.empty())
	{
		string _curData = S.substr(0, S.find("\n"));

		DATA _data;
		string _time;

		//extension
		int _iPoint = _curData.find(",");
		_data.extention = _curData.substr(0, _iPoint);
		_data.extention.erase(0, _data.extention.find("."));
		_curData.erase(0, _iPoint + 2);

		//city-name
		_iPoint = _curData.find(",");
		_data.city = _curData.substr(0, _iPoint);
		_curData.erase(0, _iPoint + 2);

		_data.time = _curData;
		_time = _curData;

		map<string, vector<string>>::iterator _iter = mapCitySeq.find(_data.city);
		if (_iter == mapCitySeq.end())
		{
			vector<string> _vecTime = { _time };
			mapCitySeq.insert(map<string, vector<string>>::value_type(_data.city, _vecTime));
		}
		else
		{
			_iter->second.emplace_back(_time);
		}

		vecOrganize.emplace_back(_data);
		S.erase(0, S.find("\n") + 1);
	}

	for (map<string, vector<string>>::iterator _iter = mapCitySeq.begin(); _iter != mapCitySeq.end(); ++_iter)
		sort(_iter->second.begin(), _iter->second.end(), compareTime);

	for (auto& _data : vecOrganize)
	{
		vector<string> _cityTimes = mapCitySeq.find(_data.city)->second;
		
		int _index = find(_cityTimes.begin(), _cityTimes.end(), _data.time) - _cityTimes.begin();
		_index += 1;

		int _cnt = _cityTimes.size();
		_cnt = to_string(_cnt).length() - to_string(_index).length();
		
		for (int i = 0; i < _cnt; ++i)
			_data.count += "0";
		_data.count += to_string(_index);
	}

	for (auto& _data : vecOrganize)
	{
		answer += _data.city;
		answer += _data.count;
		answer += _data.extention;		
		answer += "\n";
	}

	return answer;
}