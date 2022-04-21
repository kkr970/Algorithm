#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

bool cmp(vector<string> a, vector<string> b)
{
    return stoi(a[4]) > stoi(b[4]);
}

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

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> info_vec;
    unordered_map<string, vector<int>> info_map;

    for(string temp : info)
    {
        info_vec.push_back(split_string(temp));
    }
    sort(info_vec.begin(), info_vec.end(), cmp);

    for(string temp : query)
    {
        vector<string> vec = split_string(temp);

        int num = 0;
        for(vector<string> info_vec_temp : info_vec)
        {
            if(stoi(info_vec_temp[4]) < stoi(vec[4])) break;
            if(vec[0] != "-" && info_vec_temp[0] != vec[0]) continue;
            if(vec[1] != "-" && info_vec_temp[1] != vec[1]) continue;
            if(vec[2] != "-" && info_vec_temp[2] != vec[2]) continue;
            if(vec[3] != "-" && info_vec_temp[3] != vec[3]) continue;
            num++;
        }
        answer.push_back(num);
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/72412

/*
주어지는 정보와 조건에 대한 string을 공백을 기준으로 나눔
조건에 해당하는 인원을 answer에 push_back
*/