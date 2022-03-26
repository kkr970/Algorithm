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

    //<���, �Ÿ�>
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
����
1�� ���� ���� �ָ� ������ ����� ��
BFS�� ����ؼ�, �� ��忡 �ش��ϴ� �Ÿ��� ���
���1) ���ο� �迭�� �����ؼ� index=����ȣ �� �̿�, �� index�� �Ÿ��� ����
    �ִ� �Ÿ��� index�� ���� ��ȯ
���2) �� bfs�� ������ �����ؼ� �ִ� ������ �ش��ϴ� ����� ���� ��ȯ

*/