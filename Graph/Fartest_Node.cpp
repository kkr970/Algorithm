#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int distance = 1;
    int fartest = 1;
    int* isVisited = new int[n + 1]{0};
    
    for(int i = 0 ; i < edge.size() ; i++)
        sort(edge[i].begin(), edge[i].end());
    sort(edge.begin(), edge.end());

    //<노드, 거리>
    queue<pair<int, int>> q;

    q.push(make_pair(1, distance));
    isVisited[1] = distance;
    while(!q.empty())
    {
        pair<int, int> cur_node = q.front();
        if( distance != q.front().second )
            distance++;
        q.pop();

        for(vector<int> temp : edge)
        {
            if( isVisited[temp[1]] == 0 && temp[0] == cur_node.first )
            {
                if(fartest == distance)
                    fartest++;
                isVisited[temp[1]] = distance + 1;
                q.push(make_pair(temp[1], distance + 1));
            }
            if(temp[0] > cur_node.first)
                break;
        }
    }

    for(int i = 1 ; i < n + 1 ; i++)
        if(isVisited[i] == fartest)
            answer++;

    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/49189

/*
생각
1번 노드와 가장 멀리 떨어진 노드의 수
BFS를 사용해서, 각 노드에 해당하는 거리를 계산
방법1) 새로운 배열을 생성해서 index=노드번호 를 이용, 각 index에 거리를 저장
    최대 거리인 index의 수를 반환
방법2) 각 bfs를 레벨당 저장해서 최대 레벨에 해당하는 노드의 수를 반환

*/