#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps) {
    int answer = 0;
    queue<pair<int, int>> q;

    int n = maps[0].size() - 1; //j 가로
    int m = maps.size() - 1;    //i 세로

    int i = 0;
    int j = 0;

    q.push(make_pair(i, j));
    maps[i][j] += 1;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        i = cur.first;
        j = cur.second;
        if(i == m && j == n) return maps[i][j] - 1;
        q.pop();

        if(i != 0 && maps[i-1][j] == 1)
        {
            q.push(make_pair(i-1, j));
            maps[i-1][j] += maps[i][j];
        }
        if(i != m && maps[i+1][j] == 1)
        {
            q.push(make_pair(i+1, j));
            maps[i+1][j] += maps[i][j];
        }
        if(j != 0 && maps[i][j-1] == 1)
        {
            q.push(make_pair(i, j-1));
            maps[i][j-1] += maps[i][j];
        }
        if(j != n && maps[i][j+1] == 1)
        {
            q.push(make_pair(i, j+1));
            maps[i][j+1] += maps[i][j];
        }
    }
    return -1;
}

// https://programmers.co.kr/learn/courses/30/lessons/1844

/*
BFS를 이용해 도착지점에 도착하면 경로의 거리를 return
    시작지점, 도착지점을 포함함
도착하지 못하는 경우 -1을 리턴

*/