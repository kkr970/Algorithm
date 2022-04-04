#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

vector<string> split(string &s, char delimiter)
{
    vector<string> elems;
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, delimiter))
    {
        elems.push_back(temp);
    }

    return elems;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_map<string, int> index_map;
    unordered_map<string, set<string>> report_map;
    set<string>::iterator iter;

    for(int i = 0 ; i < id_list.size() ; i++)
    {
        index_map[id_list[i]] = i;
    }

    for(string temp : report)
    {
        vector<string> split_temp = split(temp, ' ');
        report_map[split_temp[1]].insert(split_temp[0]);
    }
    
    for(string temp : id_list)
    {
        if(report_map[temp].size() >= k)
        {
            for(iter = report_map[temp].begin() ; iter != report_map[temp].end(); iter++)
            {
                answer[index_map[*iter]]++;
            }
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/92334

/*
������ �Ű� �ؼ� �� ����� k�̻� �Ű� �޾��� ���,
������ ������ �ްԵ�
�� ������ ���� return
-���� ������ ���� ������ ������ �Ű��� ���, 1���� �Ű�� ó��

string�� �Է¹޾Ƽ� ���� �������� ����
�տ� id�� user, �ڿ� id�� reported
map�� �����ϴµ�, �Ű� ���� ����� key, �Ű� �� ������� value�� set�� �������

map���� value set�� ũ�Ⱑ k�̻��� ���, set�� ���鿡 �ش��ϴ� ����ڵ鿡�� ������ ����
    -> ����ڵ��� ã�� index�� �ʿ��ѵ�, �̸� �����ϴ� �͵� ���� �����ؾ� �ҵ�?
*/