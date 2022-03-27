#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1);
    vector<int> distance(n+1, -1);
    queue<int> q;

    for(int i = 0 ; i < edge.size() ; i++)
    {
        int from = edge[i][0];
        int to = edge[i][1];

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    distance[1] = 0;
    q.push(1);

    while(!q.empty())
    {
        int cur_node = q.front();
        q.pop();

        for(int next : graph[cur_node])
        {
            if(distance[next] == -1)
            {
                //현재 노드까지의 거리 + 1을 저장함
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    int fartest = *max_element(distance.begin(), distance.end());

    for(int i = 0 ; i < distance.size() ; i++)
    {
        if(distance[i] == fartest)
            answer++;
    }

    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/49189

/*
배울 점
그래프에 대해 기초적인 내용을 사용한 문제
그래프에 관한 내용을 공부해야 할 듯

그래프는 벡터를 사용해 노드에서 연결되어진 노드를 저장함
vector distance를 만들어서 각 index == node번호, value는 거리를 저장하였음
queue를 사용해 BFS, q는 노드의 번호만 사용하였음

*/