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
가로, 세로가 주어짐, arr[세로][가로]
특정 지역은 물웅덩이라 지나갈 수 없음 0~10개

새로운 배열 arr[세로][가로]를 만들어서
배열에 수를 저장, value는 현재 위치에 도착하는 모든 경로 (하, 우 밖에 이동 못함)
물웅덩이일 경우, 패스
m==4, n==3, [2, 2]
 1 1 1 1
 1 x 1 2
 1 1 2 4
-> [i][j]가 현재 위치라면, [i-1][j]와 [i][j-1]의 값을 합하면 됨
1. 데이터가 없는 경우 무시 -> 0padding을 사용, 배열에 왼쪽과 위쪽끝에는 0으로 채워질 것
2. 물웅덩이인 경우 무시 -> puddles의 i,j 를 이용해 그 위치의 value를 -1로 초기화

->
0 0 0 0 0
0 1 1 1 1
0 1-1 1 2
0 1 1 2 4
마지막으로 return arr[m][n];

*/