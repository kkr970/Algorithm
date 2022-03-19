#include <string>
#include <vector>

using namespace std;

vector<vector<int>> network;

void dfs(bool isVisited[], int computer_num, vector<int>& v)
{
    if(!isVisited[computer_num])
    {
        isVisited[computer_num] = true;
        for(int i = 0 ; i < v.size() ; i++)
            if(v[i] == 1 && !isVisited[i])
                dfs(isVisited, i, network[i]);
    }
    else
        return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    network = computers;

    bool *isVisited = new bool[n]{false};
    
    for(int i = 0 ; i < n ; i ++)
    {
        if(!isVisited[i])
        {
            dfs(isVisited, i, network[i]);
            answer++;
        }
    }
    
    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/43162

/*
생각

func DFS
    연결된 컴퓨터를 방문, 방문을 확인

for(컴퓨터를 하나씩 확인)
{
    if(방문하지 않았던 곳)
    {
        DFS
        answer++
    }
}

*/