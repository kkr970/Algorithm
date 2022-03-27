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
                //���� �������� �Ÿ� + 1�� ������
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
��� ��
�׷����� ���� �������� ������ ����� ����
�׷����� ���� ������ �����ؾ� �� ��

�׷����� ���͸� ����� ��忡�� ����Ǿ��� ��带 ������
vector distance�� ���� �� index == node��ȣ, value�� �Ÿ��� �����Ͽ���
queue�� ����� BFS, q�� ����� ��ȣ�� ����Ͽ���

*/