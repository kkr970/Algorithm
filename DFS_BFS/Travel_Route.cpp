#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
int depth = 0;

bool cmp(vector<string>& a, vector<string>& b)
{
    return a[1] < b[1];
}

void dfs(vector<vector<string>> tickets, vector<string> v, int num, bool *isUsed)
{
    depth++;
    answer.push_back(v[1]);
    
    if(depth == tickets.size())
        return;

    for(int i = 0 ; i < tickets.size() ; i++)
    {
        if(tickets[i][0] == v[1] && !isUsed[i])
        {
            isUsed[i] = true;
            dfs(tickets, tickets[i], i, isUsed);
            if(depth == tickets.size())
                return;
        }
    }
    
    isUsed[num] = false;
    answer.pop_back();
    depth--;
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    bool *isUsed = new bool[tickets.size()]{false};
    
    sort(tickets.begin(), tickets.end(), cmp);
    
    for(int i = 0 ; i < tickets.size() ; i++)
    {
        if(tickets[i][0] == "ICN")
        {
            answer.push_back(tickets[i][0]);
            isUsed[i] = true;
            dfs(tickets, tickets[i], i, isUsed);

            if(depth == tickets.size())
                return answer;
            else
            {
                answer.clear();
                fill_n(isUsed, tickets.size(), false);
                depth = 0;
            }
        }
    }
    return answer;    
}

//https://programmers.co.kr/learn/courses/30/lessons/43164

/*
����
��� tickets�� ���
��ΰ� 2�� �̻��� ���, ���ĺ��� �ռ��� ��� ���� -> ���� ����ؾ� �ҵ�
value ������ ���� �� �� ��θ� ã��
DFS�� ����ؼ� leaf ����� �� tickets.size + 1 �� �湮�� ��� ����

--�ٸ���� Ǯ��
using namespace std;
int visited[1000000];
string ans_string = "a";

void dfs(vector<vector<string>> &tickets, string cur, string path, int depth) {
    if (depth == tickets.size()) {
        string p = path;
        if (path < ans_string) {
            ans_string = path;
        }
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (cur == tickets[i][0] && !visited[i]) {
            visited[i] = 1;
            dfs(tickets, tickets[i][1], path + tickets[i][1], depth+1);
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    dfs(tickets, "ICN", "ICN", 0);
    for (int i = 0; i < ans_string.size(); i+=3) {
        answer.push_back(ans_string.substr(i, 3));
    }
    return answer;
}

if (path < ans_string) {
    ans_string = path;
}
�� �κ��� ������ ���� �� ��
��ΰ� 2�� �̻��� ��쿡 ���ĺ� ������� return�ϰ� �Ǿ��ִµ�
�ܼ� ũ�� �񱳸� �̿��ؼ� �� ���� ����(���ĺ��� A�� ����� ��) ����ϴ� ��
*/