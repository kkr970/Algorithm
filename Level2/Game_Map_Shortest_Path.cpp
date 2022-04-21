#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps) {
    int answer = 0;
    queue<pair<int, int>> q;

    int n = maps[0].size() - 1; //j ����
    int m = maps.size() - 1;    //i ����

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
BFS�� �̿��� ���������� �����ϸ� ����� �Ÿ��� return
    ��������, ���������� ������
�������� ���ϴ� ��� -1�� ����

*/