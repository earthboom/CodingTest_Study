#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 3

// 해시 ( hash )
// 베스트앨범


//======================================================================================
//======================================================================================

vector<int> Bestelbum_03(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    map<string, int> mapLineup;
    for (int i = 0; i < plays.size(); ++i)
    {
        if(mapLineup.find(genres[i]) != mapLineup.end())
            mapLineup.emplace(map<string, int>::value_type(genres[i], plays[i]));

        mapLineup[genres[i]] += plays[i];
    }

    vector<pair<string, int>> vecLineup(mapLineup.begin(), mapLineup.end());
    sort(vecLineup.begin(), vecLineup.end(),
        [](pair<string, int>& a, pair<string, int>& b)->bool{
            return a.second > b.second;
        });

    for (pair<string, int>& best : vecLineup)
    {
        vector<pair<int, int>> playlineup;
        for (int i = 0; i < plays.size(); ++i)
        {
            if(genres[i] == best.first)
                playlineup.emplace_back(make_pair(plays[i], i));
        }

        sort(playlineup.begin(), playlineup.end(), 
            [](pair<int, int>& a, pair<int, int>& b)->bool {
                if (a.first != b.first)
                    return a.first > b.first;
                else
                    return a.second < b.second;
            });

        answer.emplace_back(playlineup[0].second);

        if(playlineup.size() > 1)
            answer.emplace_back(playlineup[1].second);
    }

    return answer;
}

//======================================================================================
//======================================================================================


//======================================================================================
//======================================================================================
typedef unordered_map<string, int> COUNT;

bool Compare(pair<int, string> _a, pair<int, string> _b)
{
    return _a.first > _b.first;
}

vector<int> Bestelbum(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    COUNT mapCount;
    for (int i = 0; i < plays.size(); ++i)
    {
        if (mapCount.find(genres[i]) == mapCount.end())
        {
            mapCount.emplace(COUNT::value_type(genres[i], plays[i]));
            continue;
        }

        mapCount[genres[i]] += plays[i];
    }

    vector<pair<int, string>> vecElbum;
    for (auto& m : mapCount)
        vecElbum.emplace_back(make_pair(m.second, m.first));

    sort(vecElbum.begin(), vecElbum.end(), 
        [](pair<int, string>& _a, pair<int, string>& _b) {
            return _a.first > _b.first;
        });


    for (auto& e : vecElbum)
    {
        vector<int> sameGenre;
        for (int i = 0; i < plays.size(); ++i)
        {
            if (e.second == genres[i])
                sameGenre.emplace_back(plays[i]);
        }

        if (sameGenre.size() == 1)
        {
            int _index = distance(plays.begin(), find(plays.begin(), plays.end(), sameGenre[0]));
            answer.emplace_back(_index);
        }
        else
        {
            sort(sameGenre.begin(), sameGenre.end(), greater<int>());

            for (int i = 0; i < 2; ++i)
            {
                int _index = distance(plays.begin(), find(plays.begin(), plays.end(), sameGenre[i]));

                if (i == 1)
                {
                    if (_index == answer[answer.size() - 1])
                        _index = distance(plays.begin(), find(plays.begin() + _index + 1, plays.end(), sameGenre[1]));
                }

                answer.emplace_back(_index);

                if (i == 1)
                    break;
            }
        }        
    }

    return answer;
}

//======================================================================================
//======================================================================================


//======================================================================================
//======================================================================================
map<int, string, greater<int>> swap_key_value(unordered_map<string, int>& _hash)
{
    map<int, string, greater<int>> _returnHash;

    for (auto const& _m : _hash)
        _returnHash.emplace(make_pair(_m.second, _m.first));

    return _returnHash;
}

vector<int> solution_bestelbum_lv3(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> hash_music_play;

    for (size_t i = 0; i < genres.size(); ++i)
    {
        auto iter_name = hash_music_play.find(genres[i]);
        if (iter_name == hash_music_play.end())
        {
            hash_music_play.emplace(unordered_map<string, int>::value_type(genres[i], plays[i]));
            continue;
        }

        iter_name->second += plays[i];
    }

    map<int, string, greater<int>> hash_alignment = swap_key_value(hash_music_play);

    for (auto& _music : hash_alignment)
    {
        vector<int> sameGenre;

        for (size_t i = 0; i < genres.size(); ++i)
        {
            if (genres[i] != _music.second) continue;

            sameGenre.emplace_back(plays[i]);
        }

        sort(sameGenre.begin(), sameGenre.end(), greater<int>());

        for (size_t i = 0; i < sameGenre.size(); ++i)
        {
            int _index = distance(plays.begin(), find(plays.begin(), plays.end(), sameGenre[i]));
            if (i == 1)
            {
                if (_index == answer[answer.size() - 1])
                    _index = distance(plays.begin(), find(plays.begin() + _index + 1, plays.end(), sameGenre[1]));
            }
            answer.emplace_back(_index);

            if (i == 1) break;
        }
    }

    return answer;
}
//======================================================================================
//======================================================================================