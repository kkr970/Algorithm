#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> player_map;

    for(string name : participant)
    {
        if(player_map.count(name) == 0)
            player_map.insert(make_pair(name, 0));
        player_map[name]++;   
    }

    for(string name : completion)
        player_map[name]--;

    for(auto it = player_map.begin() ; it != player_map.end() ; it++)
        if(it->second == 1)
        {
            answer = it->first;
            break;
        }

    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42576

/*
생각
참가자와 완주한 선수가 주어지며, 완주하지 못한 선수는 단 한명이라고 함
참가자는 동명이인이 있을 수 있다고 함
1) 참가자 - 완주자 를 하나씩 비교해서 없는 사람 찾기 -> 확실한 방법이나 엄청난 시간이 소요될 듯

2) 맵을 사용, 참가자들을 <string, bool>로 해서 통과한 사람은 true로 변경
    value가 false인 key를 answer에 저장 후 반환 -> 동명이인은 어떻게 구분?

3) 맵을 사용, 참가자들을 <string, int>로 해서 생성
    Key는 참가자 이름, value값은 참가자 이름이 한번 등장할 때 마다 +1 해서 참가한 인원을 표시
    완주자와 비교해 같은 Key값인 것을 찾아 value를 -1
    value가 0이 아닌(1인-완주하지 못한 선수는 단 한명이기 떄문에) Key를 answer에 저장 후 반환

-----다른 사람 풀이-----
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> names;

    for(int i = 0; i < participant.size(); i++)
    {
        names.insert(participant[i]);
    }

    for(int i = 0; i < completion.size(); i++)
    {
        unordered_multiset<string>::iterator itr = names.find(completion[i]);
        names.erase(itr);
    }

    return *names.begin();
}
-----다른 사람 풀이-----
-참가자, 완주자를 정렬해서
한개씩 비교, 다르면 출력
*/