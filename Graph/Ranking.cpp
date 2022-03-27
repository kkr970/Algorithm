#include <string>
#include <vector>

#include <iostream>

using namespace std;

void dfs(int n, vector<vector<int>>& v, bool isVisited[], int& info) {
    if(isVisited[n])
        return;
    isVisited[n] = true;
    info++;

    for(int i = 0 ; i < v[n].size() ; i++)
    {
        int next = v[n][i];
        dfs(next, v, isVisited, info);
    }    
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph_win(n+1);
    vector<vector<int>> graph_lose(n+1);
    
    int info = 0;
    bool* isVisited = new bool[n+1]{false};

    for(int i = 0 ; i < results.size() ; i++)
    {
        int from = results[i][0];
        int to = results[i][1];

        graph_win[from].push_back(to);
        graph_lose[to].push_back(from);
    }

    for(int i = 1 ; i <= n ; i++)
    {
        dfs(i, graph_win, isVisited, info);
        fill_n(isVisited, n+1, false);
        
        dfs(i, graph_lose, isVisited, info);
        fill_n(isVisited, n+1, false);
        
        //info는 자기 자신일때도 1을 더했음으로 2를 뺴줘야함
        //이후, 충분한 정보(n-1)을 가지고 있는 경우 answer++
        if(info - 2 == n - 1) answer++;
        info = 0;
    }

    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/49191

/*
생각
등수를 알기 위해서는 다른 선수들과의 정보가 필요함
선수 5명
[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]
1-2
2-5
3-2
4-3-2
5
이긴 정보 -> 자기 자신의 선조들

1
2-1-3-4
3-4
4
5-2
진 정보 -> 자기 자신의 자식들

1의 경우 : 이김=2 5, 짐=x           2개의 정보
2의 경우 : 이김=5,   짐=1 3 4       4개의 정보
3의 경우 : 이김=2 5, 짐=4           3개의 정보
4의 경우 : 이김=3 2, 짐=4           3개의 정보
5의 경우 : 이김=x    짐=2 1 3 4     4개의 정보

충분한 정보(n-1)을 가진 선수는 2명, return 2

-------다른사람 풀이-------

int d[101][101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++)
    {
        d[results[i][0]][results[i][1]]=1; // 승리
        d[results[i][1]][results[i][0]]=-1; // 패배
    }

    for (int i = 1; i <= n; i++)
    {
        for (int from = 1; from <= n; from++)
        {
            if (d[from][i] == 0)
            {
                continue;
            }
            for (int to = 1; to <= n; to++)
            {
                if (d[from][i] == d[i][to])
                {
                    d[from][to] = d[from][i];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            // 대소 관계가 있을 때 sum을 증가
            if(d[i][j]!=0 && (i!=j))
            {
                sum++;
            }
        }
        // 대소 관계가 모두 있다면 순위를 매길수 있는 선수
        if(sum==(n-1))
        {
            answer++;
        }
    }
    return answer;
}

플로이드-와샬 풀이라는 듯
*/