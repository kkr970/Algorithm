#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp1(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}
bool cmp2(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> genres_map;
    for(int i = 0 ; i < genres.size() ; i++)
        genres_map[genres[i]] += plays[i];

    vector<pair<string, int>> genres_vec(genres_map.begin(), genres_map.end());
    sort(genres_vec.begin(), genres_vec.end(), cmp1);

    for(auto genre : genres_vec)
    {
        map<int, int> temp;
        for(int i = 0 ; i < plays.size() ; i++)
            if(genres[i] == genre.first)
                temp.insert(make_pair(i, plays[i]));

        vector<pair<int, int>> temp_vec(temp.begin(), temp.end());
        sort(temp_vec.begin(), temp_vec.end(), cmp2);

        for(int i = 0 ; i < temp_vec.size() ; i++)
        {
            if(i == 2) break;
            answer.push_back(temp_vec[i].first);
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42579

/*
����
-�帣�� �� ������ ���
-�帣�� �ش��ϴ� ���� ������
-���� ���� ���� �帣 �� 2�� ����
-���� ��� Ƚ���� ���, index�� �տ��ִ� �뷡�� ����

*/