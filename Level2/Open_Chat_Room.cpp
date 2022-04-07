#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

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

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickname;

    for(string temp : record)
    {
        vector<string> split_temp = split(temp, ' ');
        if(split_temp[0] != "Leave")
            nickname[split_temp[1]] = split_temp[2];
    }

    for(string temp : record)
    {
        vector<string> split_temp = split(temp, ' ');
        string str = "";
        if(split_temp[0] == "Enter")
        {
            str = nickname[split_temp[1]] + "���� ���Խ��ϴ�.";
        }
        else if(split_temp[0] == "Leave")
        {
            str = nickname[split_temp[1]] + "���� �������ϴ�.";
        }
        else if(split_temp[0] == "Change")
            continue;
        answer.push_back(str);
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42888

/*
����
map�� ��� <uid, nickname>

Enter�� ������ hash�� ����
Change�� ������ hash�� ����
Leave�� ����� ����ϸ� ��

���� record�� �ٽ� ���鼭 ��ɾ�� uid�� ���� answer�� ����
*/