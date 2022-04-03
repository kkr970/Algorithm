#include <string>
#include <vector>

#define PRIME_NUM 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int route[100][100] = {0};

    for(int i = 0 ; i < puddles.size() ; i++)
    {
        if(puddles[i].size() == 2)
            route[puddles[i][0]-1][puddles[i][1]-1] = -1;
    }
    
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i == 0 && j == 0)
            {
                route[i][j] = 1;
                continue;
            }
            if(route[i][j] != -1)
            {
                int up = 0;
                int left = 0;
                if(i != 0)
                {
                    up = route[i-1][j];
                }
                if(j != 0)
                {
                    left = route[i][j-1];
                }

                if(left == -1)
                {
                    route[i][j] = up;
                }
                else if(up == -1)
                {
                    route[i][j] = left;
                }
                else 
                {
                    route[i][j] = (up + left) % PRIME_NUM;
                }
            }
        }
    }
        
    return route[m-1][n-1];
}


// https://programmers.co.kr/learn/courses/30/lessons/42898

/*
����, ���ΰ� �־���, arr[����][����]
Ư�� ������ �������̶� ������ �� ���� 0~10��

���ο� �迭 arr[����][����]�� ����
�迭�� ���� ����, value�� ���� ��ġ�� �����ϴ� ��� ��� (��, �� �ۿ� �̵� ����)
���������� ���, �н�
m==4, n==3, [2, 2]
 1 1 1 1
 1 x 1 2
 1 1 2 4
-> [i][j]�� ���� ��ġ���, [i-1][j]�� [i][j-1]�� ���� ���ϸ� ��
1. �����Ͱ� ���� ��� ���� -> 0padding�� ���, �迭�� ���ʰ� ���ʳ����� 0���� ä���� ��
2. ���������� ��� ���� -> puddles�� i,j �� �̿��� �� ��ġ�� value�� -1�� �ʱ�ȭ

->
0 0 0 0 0
0 1 1 1 1
0 1-1 1 2
0 1 1 2 4
���������� return arr[m][n];

*/