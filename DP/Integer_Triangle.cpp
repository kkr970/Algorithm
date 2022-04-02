#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for(int i = triangle.size() - 1 ; i > 0 ; i--)
    {
        for(int j = 0 ; j < triangle[i].size() - 1 ; j++)
        {
            if(triangle[i][j] > triangle[i][j+1])
                triangle[i - 1][j] = triangle[i][j] + triangle[i - 1][j];
            else
                triangle[i - 1][j] = triangle[i][j+1] + triangle[i - 1][j];
        }
    }
    return triangle[0][0];
}

// https://programmers.co.kr/learn/courses/30/lessons/43105

/*
����
���� �迭�� �̵��� ��
0->0, 1
1->1, 2
n->n, n+1 �� �̵��� ������

�Ǵ� �� �Ʒ�����
n, n+1->n
n, n+1�� ū�ɷ� ����
*/