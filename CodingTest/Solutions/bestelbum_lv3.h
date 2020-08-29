#pragma once

#include "stdafx.h"

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