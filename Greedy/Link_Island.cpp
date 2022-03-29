#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    bool* isLinked = new bool[n]{false};
    // pair<����ġ, ����ȣ>
    vector<vector<pair<int, int>>> graph(n + 1);

    for(int i = 0 ; i < costs.size() ; i++)
    {
        int from = costs[i][0];
        int to = costs[i][1];
        int weight = costs[i][2];

        graph[from].push_back(make_pair(weight, to));
        graph[to].push_back(make_pair(weight, from));
    }

    //pQ<����ġ, ����ȣ>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
    pQ.push(make_pair(0, costs[0][0]));

    //prim
    while(!pQ.empty())
    {
        int cur_node = pQ.top().second;
        int cur_weight = pQ.top().first;
        pQ.pop();

        if(isLinked[cur_node]) continue;
        isLinked[cur_node] = true;
        answer += cur_weight;

        for(int i = 0 ; i < graph[cur_node].size() ; i++)
        {
            int next_node = graph[cur_node][i].second;
            if(isLinked[next_node]) continue;
            int next_weight = graph[cur_node][i].first;
            pQ.push(make_pair(next_weight, next_node));
        }
    }

    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/42861
/*
����
����ġ �׷������� �ּ� ���� Ʈ���� ����� �� ����

-kruskal
��� ����ġ �� ���� ����ġ�� ����
����Ŭ�� ������ ������ ���� ���� ����ġ�� ����
    t
�ݺ�

-prim
�׷������� �ƹ� ������ ����
������ �����鿡�� ����ġ�� ���� ���� ����
    ->������ � ������ �����ߴ��� �˾ƾ���
�ݺ�

---------ũ�罺Į �˰���----------
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int d[101];

int getParent(int node){
    if(node == d[node]){
        return node;
    }
    else return d[node] = getParent(d[node]);
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {

    int answer = 0;
    for(int i =0; i<n; i++){
        d[i] = i;
    }
    sort(costs.begin(), costs.end(), compare);
    for(int i=0; i<costs.size(); i++){
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];

        if(start != end){
            d[end] = start;

            answer += cost;
        }
    }


    return answer;
}
*/