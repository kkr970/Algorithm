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
생각
다음 배열로 이동할 때
0->0, 1
1->1, 2
n->n, n+1 로 이동이 가능함

또는 맨 아래부터
n, n+1->n
n, n+1중 큰걸로 선택
*/