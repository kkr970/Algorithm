#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

vector<string> split_string(string temp)
{
    vector<string> vec;
    string str = "";
    for(int i = 0 ; i < temp.length() ; i++)
    {
        if(temp[i] == ' ')
        {
            if(str != "and")
                vec.push_back(str);
            str = "";
        }
        else
            str += temp[i];
    }
    vec.push_back(str);
    return vec;
}

vector<int> solution(vector<string> infos, vector<string> queries) {
    vector<int> answer;
    unordered_map<string, vector<int>> info_map;

    for(string info : infos)
    {
        vector<string> key = split_string(info);
        for(int i = 0 ; i < 16 ; i++)
        {
            string temp = "";
            for(int j = 0 ; j < 4 ; j++)
                temp += (i & (1 << j)) ? key[j] : "-";
            info_map[temp].push_back(stoi(key[4]));
        }
    }

    for(auto &iter : info_map)
        sort(iter.second.begin(), iter.second.end());

    for(string query : queries)
    {
        vector<string> key = split_string(query);

        string temp = key[0] + key[1] + key[2] + key[3];
        vector<int> temp_info = info_map[temp];

        int number = temp_info.end() - lower_bound(temp_info.begin(), temp_info.end(), stoi(key[4]));
        answer.push_back(number);
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/72412

/*
주어지는 정보와 조건에 대한 string을 공백을 기준으로 나눔
map에 주어지는 정보를 string으로 변경, key값으로 해서 점수를 value로 저장
단, 모든 조건에 대해서 key를 저장하는데 info에는 정보가 4개가 있음
a, b, c, d, 점수
이 abcd는 -가 될 수도 있기에
abcd
abc-
ab-d
a-bd
-bcd
등
모든 조건에 대해 저장함

이후, query에 조건을 string으로 변환한 후,
점수를 lower_bound를 이용해 조건보다 큰 수중 가장 작은 index를 반환하여
end-index를 행해 높은 점수의 수를 세어 answer에 push_back
*/