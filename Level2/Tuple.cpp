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
s는 string으로 주어짐
{{}, {}}인데 내부 {}들을 모아 vector<vector<>>로 만들자
생각1
만든 벡터<벡터>를 이용해 제일 긴 벡터를 선택
숫자가 많이 사용된 순으로 answer에 입력

생각2
s를 숫자가 나오는 것을 뽑음
map에 저장, ++
value 순으로 key값을 출력
*/