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
����
�����ڿ� ������ ������ �־�����, �������� ���� ������ �� �Ѹ��̶�� ��
�����ڴ� ���������� ���� �� �ִٰ� ��
1) ������ - ������ �� �ϳ��� ���ؼ� ���� ��� ã�� -> Ȯ���� ����̳� ��û�� �ð��� �ҿ�� ��

2) ���� ���, �����ڵ��� <string, bool>�� �ؼ� ����� ����� true�� ����
    value�� false�� key�� answer�� ���� �� ��ȯ -> ���������� ��� ����?

3) ���� ���, �����ڵ��� <string, int>�� �ؼ� ����
    Key�� ������ �̸�, value���� ������ �̸��� �ѹ� ������ �� ���� +1 �ؼ� ������ �ο��� ǥ��
    �����ڿ� ���� ���� Key���� ���� ã�� value�� -1
    value�� 0�� �ƴ�(1��-�������� ���� ������ �� �Ѹ��̱� ������) Key�� answer�� ���� �� ��ȯ

-----�ٸ� ��� Ǯ��-----
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
-----�ٸ� ��� Ǯ��-----
-������, �����ڸ� �����ؼ�
�Ѱ��� ��, �ٸ��� ���
*/