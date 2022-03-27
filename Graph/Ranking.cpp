#include <string>
#include <vector>

#include <iostream>

using namespace std;

void dfs(int n, vector<vector<int>>& v, bool isVisited[], int& info) {
    if(isVisited[n])
        return;
    isVisited[n] = true;
    info++;

    for(int i = 0 ; i < v[n].size() ; i++)
    {
        int next = v[n][i];
        dfs(next, v, isVisited, info);
    }    
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph_win(n+1);
    vector<vector<int>> graph_lose(n+1);
    
    int info = 0;
    bool* isVisited = new bool[n+1]{false};

    for(int i = 0 ; i < results.size() ; i++)
    {
        int from = results[i][0];
        int to = results[i][1];

        graph_win[from].push_back(to);
        graph_lose[to].push_back(from);
    }

    for(int i = 1 ; i <= n ; i++)
    {
        dfs(i, graph_win, isVisited, info);
        fill_n(isVisited, n+1, false);
        
        dfs(i, graph_lose, isVisited, info);
        fill_n(isVisited, n+1, false);
        
        //info�� �ڱ� �ڽ��϶��� 1�� ���������� 2�� �������
        //����, ����� ����(n-1)�� ������ �ִ� ��� answer++
        if(info - 2 == n - 1) answer++;
        info = 0;
    }

    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/49191

/*
����
����� �˱� ���ؼ��� �ٸ� ��������� ������ �ʿ���
���� 5��
[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]
1-2
2-5
3-2
4-3-2
5
�̱� ���� -> �ڱ� �ڽ��� ������

1
2-1-3-4
3-4
4
5-2
�� ���� -> �ڱ� �ڽ��� �ڽĵ�

1�� ��� : �̱�=2 5, ��=x           2���� ����
2�� ��� : �̱�=5,   ��=1 3 4       4���� ����
3�� ��� : �̱�=2 5, ��=4           3���� ����
4�� ��� : �̱�=3 2, ��=4           3���� ����
5�� ��� : �̱�=x    ��=2 1 3 4     4���� ����

����� ����(n-1)�� ���� ������ 2��, return 2

-------�ٸ���� Ǯ��-------

int d[101][101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++)
    {
        d[results[i][0]][results[i][1]]=1; // �¸�
        d[results[i][1]][results[i][0]]=-1; // �й�
    }

    for (int i = 1; i <= n; i++)
    {
        for (int from = 1; from <= n; from++)
        {
            if (d[from][i] == 0)
            {
                continue;
            }
            for (int to = 1; to <= n; to++)
            {
                if (d[from][i] == d[i][to])
                {
                    d[from][to] = d[from][i];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            // ��� ���谡 ���� �� sum�� ����
            if(d[i][j]!=0 && (i!=j))
            {
                sum++;
            }
        }
        // ��� ���谡 ��� �ִٸ� ������ �ű�� �ִ� ����
        if(sum==(n-1))
        {
            answer++;
        }
    }
    return answer;
}

�÷��̵�-�ͼ� Ǯ�̶�� ��
*/