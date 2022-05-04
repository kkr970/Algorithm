#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100001 * n;
    vector<vector<pair<int, int>>> graph(n+1); // <가중치, 노드>

    for(vector<int> fare : fares)
    {
        graph[fare[0]].push_back(make_pair(fare[2], fare[1]));
        graph[fare[1]].push_back(make_pair(fare[2], fare[0]));
    }

    //합승할 노드의 위치
    for(int i = 1 ; i <= n ; i++)
    {
        //합승지점에서 시작하는 다익스트라 알고리즘, 각자 위치 까지의 가중치를 얻기 위함
        vector<int> weight(n+1, 100001 * n);
        weight[i] = 0;
        priority_queue<pair<int, int>> pq; // <가중치, 노드>
        pq.push(make_pair(0, i));
        while(!pq.empty())
        {
            int cur_node = pq.top().second;
            pq.pop();
            for(int i = 0 ; i < graph[cur_node].size() ; i++)
            {
                int next_node = graph[cur_node][i].second;
                int next_weight = graph[cur_node][i].first + weight[cur_node];
                if(next_weight < weight[next_node])
                {
                    weight[next_node] = next_weight;
                    pq.push(make_pair(-1*next_weight, next_node));
                }
            }
        }
        int fare_total = weight[s] + weight[a] + weight[b];
        if(answer > fare_total) answer = fare_total;
    }
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/72413

/*
모든 지역, 가격은 노드와 가중치로 생각하여 그래프를 만듬(양방향)

A,B가 a, b에 도착해야 함
1) 각자 a, b로 출발하는 경우
2) 특정 노드 c에 도착한 후, 각자 a, b로 출발하는 경우
    ->c는 어떤 노드가 선택될지 모름으로 모든 노드에 대해 실행

이동에는 최단거리알고리즘을 사용하여 거리를 측정
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100001 * n;
    vector<vector<pair<int, int>>> graph(n+1); // <가중치, 노드>

    for(vector<int> fare : fares)
    {
        graph[fare[0]].push_back(make_pair(fare[2], fare[1]));
        graph[fare[1]].push_back(make_pair(fare[2], fare[0]));
    }

    //s지점에서 시작하는 다익스트라 알고리즘, 합승할 위치까지의 가중치를 얻기 위함
    vector<int> weight1(n+1, 100001 * n);
    weight1[s] = 0;
    priority_queue<pair<int, int>> pq1; // <가중치, 노드>
    pq1.push(make_pair(0, s));
    while(!pq1.empty())
    {
        int cur_node = pq1.top().second;
        pq1.pop();
        for(int i = 0 ; i < graph[cur_node].size() ; i++)
        {
            int next_node = graph[cur_node][i].second;
            int next_weight = graph[cur_node][i].first + weight1[cur_node];
            if(next_weight < weight1[next_node])
            {
                weight1[next_node] = next_weight;
                pq1.push(make_pair(-1*next_weight, next_node));
            }
        }
    }

    //합승할 노드의 위치
    for(int i = 1 ; i <= n ; i++)
    {
        //합승지점에서 시작하는 다익스트라 알고리즘, 각자 위치 까지의 가중치를 얻기 위함
        vector<int> weight2(n+1, 100001 * n);
        weight2[i] = 0;
        priority_queue<pair<int, int>> pq2; // <가중치, 노드>
        pq2.push(make_pair(0, i));
        while(!pq2.empty())
        {
            int cur_node = pq2.top().second;
            pq2.pop();
            for(int i = 0 ; i < graph[cur_node].size() ; i++)
            {
                int next_node = graph[cur_node][i].second;
                int next_weight = graph[cur_node][i].first + weight2[cur_node];
                if(next_weight < weight2[next_node])
                {
                    weight2[next_node] = next_weight;
                    pq2.push(make_pair(-1*next_weight, next_node));
                }
            }
        }
        int fare_total = weight1[i] + weight2[a] + weight2[b];
        if(answer > fare_total) answer = fare_total;
    }

    return answer;
}
-------------------------------------다른생각----------------------------------------------------
출발지점을 합승하여 가는 노드라고 생각하면
A목적지 a
B목적지 b
원래출발지 s
같이 합승할 목적지 n
-> 원래라면 s->n + n->a + n->b 로 계산
    다른 계산 방법 n->s + n->a + n->b로 한번의 다익스트라 알고리즘으로 해결이 가능함
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100001 * n;
    vector<vector<pair<int, int>>> graph(n+1); // <가중치, 노드>

    for(vector<int> fare : fares)
    {
        graph[fare[0]].push_back(make_pair(fare[2], fare[1]));
        graph[fare[1]].push_back(make_pair(fare[2], fare[0]));
    }

    //합승할 노드의 위치
    for(int i = 1 ; i <= n ; i++)
    {
        //합승지점에서 시작하는 다익스트라 알고리즘, 각자 위치 까지의 가중치를 얻기 위함
        vector<int> weight(n+1, 100001 * n);
        weight[i] = 0;
        priority_queue<pair<int, int>> pq; // <가중치, 노드>
        pq.push(make_pair(0, i));
        while(!pq.empty())
        {
            int cur_node = pq.top().second;
            pq.pop();
            for(int i = 0 ; i < graph[cur_node].size() ; i++)
            {
                int next_node = graph[cur_node][i].second;
                int next_weight = graph[cur_node][i].first + weight[cur_node];
                if(next_weight < weight[next_node])
                {
                    weight[next_node] = next_weight;
                    pq.push(make_pair(-1*next_weight, next_node));
                }
            }
        }
        int fare_total = weight[s] + weight[a] + weight[b];
        if(answer > fare_total) answer = fare_total;
    }
    return answer;
}
*/