#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    bool* isLinked = new bool[n]{false};
    // pair<가중치, 노드번호>
    vector<vector<pair<int, int>>> graph(n + 1);

    for(int i = 0 ; i < costs.size() ; i++)
    {
        int from = costs[i][0];
        int to = costs[i][1];
        int weight = costs[i][2];

        graph[from].push_back(make_pair(weight, to));
        graph[to].push_back(make_pair(weight, from));
    }

    //pQ<가중치, 노드번호>
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
생각
가중치 그래프에서 최소 신장 트리를 만드는 것 같음

-kruskal
모든 가중치 중 작은 가중치를 선택
사이클이 생기지 않으면 다음 작은 가중치를 선택
    t
반복

-prim
그래프에서 아무 정점을 선택
인접한 정점들에서 가중치가 낮은 정점 선택
    ->정점이 어떤 정점과 인접했는지 알아야함
반복

---------크루스칼 알고리즘----------
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