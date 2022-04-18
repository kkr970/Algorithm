#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <iostream>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> map;
    
    string temp = "";
    for(char c : s)
    {
        if('0' <= c && c <= '9' )
        {
            temp += c;
        }
        else if(temp != "")
        {
            int i = stoi(temp);
            map[i]++;
            temp = "";
        }
    }

    vector<pair<int, int>> map_vec(map.begin(), map.end());
    sort(map_vec.begin(), map_vec.end(), cmp);

    for(pair<int, int> temp : map_vec)
        answer.push_back(temp.first);

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/64065

/*
s�� string���� �־���
{{}, {}}�ε� ���� {}���� ��� vector<vector<>>�� ������
����1
���� ����<����>�� �̿��� ���� �� ���͸� ����
���ڰ� ���� ���� ������ answer�� �Է�

����2
s�� ���ڰ� ������ ���� ����
map�� ����, ++
value ������ key���� ���
*/