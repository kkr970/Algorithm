#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    vector<vector<pair<int, int>>> graph(N+1); // <가중치, 노드>
    for(int i = 0 ; i < road.size() ; i++)
    {
        graph[road[i][0]].push_back(make_pair(road[i][2], road[i][1]));
        graph[road[i][1]].push_back(make_pair(road[i][2], road[i][0]));
    }

    vector<int> weight(N+1, 500001);//최단거리 저장 벡터
    weight[1] = 0;
    priority_queue<pair<int, int>> pq; // <가중치 , 노드>
    pq.push(make_pair(0, 1));
    while(!pq.empty())
    {
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < graph[cur].size() ; i++)
        {
            int next = graph[cur][i].second;
            int next_weight = graph[cur][i].first + weight[cur];
            if(next_weight < weight[next])
            {
                weight[next] = next_weight;
                pq.push(make_pair(-1*next_weight, next));
            }
        }
    }

    for(int i = 1 ; i < N+1 ; i++)
        if(weight[i] <= K) answer++;

    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/12978

/*
그래프로 만들어서
BFS를 이용
벡터를 만들어서 각 index=node 에 가장 낮은 가중치를 저장함
현재 노드와 연결되어진 각 다음 노드를 보면서, 가중치+현재노드가중치 가 저장되어진 다음노드가중치보다 낮으면 값을 변경함
모든 노드에 대해 가중치를 변경한 뒤,
가중치를 보며 K보다 작으면 answer++

*/

