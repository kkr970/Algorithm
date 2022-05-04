#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100001 * n;
    vector<vector<pair<int, int>>> graph(n+1); // <����ġ, ���>

    for(vector<int> fare : fares)
    {
        graph[fare[0]].push_back(make_pair(fare[2], fare[1]));
        graph[fare[1]].push_back(make_pair(fare[2], fare[0]));
    }

    //�ս��� ����� ��ġ
    for(int i = 1 ; i <= n ; i++)
    {
        //�ս��������� �����ϴ� ���ͽ�Ʈ�� �˰���, ���� ��ġ ������ ����ġ�� ��� ����
        vector<int> weight(n+1, 100001 * n);
        weight[i] = 0;
        priority_queue<pair<int, int>> pq; // <����ġ, ���>
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
��� ����, ������ ���� ����ġ�� �����Ͽ� �׷����� ����(�����)

A,B�� a, b�� �����ؾ� ��
1) ���� a, b�� ����ϴ� ���
2) Ư�� ��� c�� ������ ��, ���� a, b�� ����ϴ� ���
    ->c�� � ��尡 ���õ��� ������ ��� ��忡 ���� ����

�̵����� �ִܰŸ��˰����� ����Ͽ� �Ÿ��� ����
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100001 * n;
    vector<vector<pair<int, int>>> graph(n+1); // <����ġ, ���>

    for(vector<int> fare : fares)
    {
        graph[fare[0]].push_back(make_pair(fare[2], fare[1]));
        graph[fare[1]].push_back(make_pair(fare[2], fare[0]));
    }

    //s�������� �����ϴ� 1 ���ͽ�Ʈ�� �˰���, �ս��� ��ġ������ ����ġ�� ��� ����
    vector<int> weight1(n+1, 100001 * n);
    weight1[s] = 0;
    priority_queue<pair<int, int>> pq1; // <����ġ, ���>
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

    //�ս��� ����� ��ġ
    for(int i = 1 ; i <= n ; i++)
    {
        //�ս��������� �����ϴ� 2 ���ͽ�Ʈ�� �˰���, ���� ��ġ ������ ����ġ�� ��� ����
        vector<int> weight2(n+1, 100001 * n);
        weight2[i] = 0;
        priority_queue<pair<int, int>> pq2; // <����ġ, ���>
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
-------------------------------------�ٸ�����----------------------------------------------------
��������� �ս��Ͽ� ���� ����� �����ϸ�
A������ a
B������ b
��������� s
���� �ս��� ������ n
-> ������� s->n + n->a + n->b �� ���
    �ٸ� ��� ��� n->s + n->a + n->b�� �ѹ��� ���ͽ�Ʈ�� �˰������� �ذ��� ������
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100001 * n;
    vector<vector<pair<int, int>>> graph(n+1); // <����ġ, ���>

    for(vector<int> fare : fares)
    {
        graph[fare[0]].push_back(make_pair(fare[2], fare[1]));
        graph[fare[1]].push_back(make_pair(fare[2], fare[0]));
    }

    //�ս��� ����� ��ġ
    for(int i = 1 ; i <= n ; i++)
    {
        //�ս��������� �����ϴ� ���ͽ�Ʈ�� �˰���, a, b, s ������ ����ġ�� ��� ����
        vector<int> weight(n+1, 100001 * n);
        weight[i] = 0;
        priority_queue<pair<int, int>> pq; // <����ġ, ���>
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