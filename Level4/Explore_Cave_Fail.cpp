#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#define MAX_NODE 200001

using namespace std;

vector<vector<int>> graph(MAX_NODE);
bool isVisited[MAX_NODE];
int cnt_node;

unordered_map<int, int> ordered_map;
unordered_map<int, int> reserved;

void dfs(int cur_node)
{
    if(!isVisited[ordered_map[cur_node]])
    {
        reserved[ordered_map[cur_node]] = cur_node;
        return;
    }
    isVisited[cur_node] = true;
    cnt_node++;

    if(reserved.find(cur_node) != reserved.end())
    {
        dfs(reserved[cur_node]);
    }

    for(int i = 0 ; i < graph[cur_node].size() ; i++)
    {
        int next_node = graph[cur_node][i];
        if(!isVisited[next_node])
        {
            dfs(next_node);
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(int i = 0 ; i < order.size() ; i++)
    {
        if(order[i][1] == 0) return false;
        ordered_map[order[i][1]] = order[i][0];
    }

    for(int i = 0 ; i < n - 1 ; i++)
    {
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }

    fill_n(isVisited, n+1, false);
    isVisited[0] = true;
    cnt_node = 1;
    for(int i = 0 ; i < graph[0].size() ; i++)
        dfs(graph[0][i]);

    
    if(cnt_node == n) return true;
    return false;
}

// https://programmers.co.kr/learn/courses/30/lessons/67260

/*
graph, 노드의 수는 n개, 사이클x
order에는 1을 방문해야 2를 방문할 수 있음

생각1
DFS로 탐색
탐색도중 order중에 먼저 방문해야 하는 곳을 만나면
    처음부터 다시 DFS
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#define MAX_NODE 200001

using namespace std;

unordered_map<int, int> lock;
unordered_map<int, int> key;
unordered_map<int, int> order_map; // <key, lock>

vector<int> locked;
bool chk_erase;

vector<vector<int>> graph(MAX_NODE);
bool isVisited[MAX_NODE];
int cnt_node;

void dfs(int cur_node)
{
    if(isVisited[cur_node]) return;
    if(lock.find(cur_node) != lock.end())
    {
        locked.insert(locked.begin(), cur_node);
        return;
    }
    isVisited[cur_node] = true;
    cnt_node++;
    
    for(int i = 0 ; i < graph[cur_node].size() ; i++)
    {
        int next_node = graph[cur_node][i];
        if(!isVisited[next_node])
        {
            if(lock.find(next_node) != lock.end())
            {
                locked.push_back(next_node);
                continue;
            }
            if(key.find(next_node) != key.end())
            {
                chk_erase = true;
                lock.erase(order_map[next_node]);
                key.erase(next_node);
            }
            dfs(graph[cur_node][i]);
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    chk_erase = true;
    cnt_node = 0;

    for(int i = 0 ; i < n - 1 ; i++)
    {
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }

    for(int i = 0 ; i < order.size() ; i++)
    {
        if(order[i][1] == 0) return false;
        order_map[order[i][0]] = order[i][1];
        key[order[i][0]] = 1;
        lock[order[i][1]] = 1;
    }

    fill_n(isVisited, n+1, false);
    dfs(0);
    while(!locked.empty() && chk_erase)
    {
        for(int i = 0 ; i < locked.size() ; i++)
        {
            dfs(locked[locked.size() - 1]);
            locked.pop_back();
        }
    }

    if(cnt_node == n) return true;
    return false;
}
*/