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
생각
-장르당 곡 갯수를 기록
-장르에 해당하는 곡을 가져옴
-가장 곡이 많은 장르 중 2개 선택
-같은 재생 횟수일 경우, index가 앞에있는 노래를 선택

*/