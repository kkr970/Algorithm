#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    vector<vector<pair<int, int>>> graph(N+1); // <����ġ, ���>
    for(int i = 0 ; i < road.size() ; i++)
    {
        graph[road[i][0]].push_back(make_pair(road[i][2], road[i][1]));
        graph[road[i][1]].push_back(make_pair(road[i][2], road[i][0]));
    }

    vector<int> weight(N+1, 500001);//�ִܰŸ� ���� ����
    weight[1] = 0;
    priority_queue<pair<int, int>> pq; // <����ġ , ���>
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
�׷����� ����
BFS�� �̿�
���͸� ���� �� index=node �� ���� ���� ����ġ�� ������
���� ���� ����Ǿ��� �� ���� ��带 ���鼭, ����ġ+�����尡��ġ �� ����Ǿ��� ������尡��ġ���� ������ ���� ������
��� ��忡 ���� ����ġ�� ������ ��,
����ġ�� ���� K���� ������ answer++

*/

