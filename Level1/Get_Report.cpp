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
유저가 신고를 해서 그 대상이 k이상 신고를 받았을 경우,
유저는 메일을 받게됨
그 메일의 수를 return
-같은 유저가 같은 유저를 여러번 신고할 경우, 1번의 신고로 처리

string을 입력받아서 띄어쓰기 기준으로 나눔
앞에 id는 user, 뒤에 id는 reported
map에 저장하는데, 신고 받은 사람이 key, 신고 한 사람들을 value로 set에 집어넣음

map에서 value set의 크기가 k이상인 경우, set의 값들에 해당하는 사용자들에게 메일을 전송
    -> 사용자들을 찾는 index가 필요한데, 이를 저장하는 것도 따로 제작해야 할듯?
*/