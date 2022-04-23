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
�־����� ������ ���ǿ� ���� string�� ������ �������� ����
map�� �־����� ������ string���� ����, key������ �ؼ� ������ value�� ����
��, ��� ���ǿ� ���ؼ� key�� �����ϴµ� info���� ������ 4���� ����
a, b, c, d, ����
�� abcd�� -�� �� ���� �ֱ⿡
abcd
abc-
ab-d
a-bd
-bcd
��
��� ���ǿ� ���� ������

����, query�� ������ string���� ��ȯ�� ��,
������ lower_bound�� �̿��� ���Ǻ��� ū ���� ���� ���� index�� ��ȯ�Ͽ�
end-index�� ���� ���� ������ ���� ���� answer�� push_back
*/