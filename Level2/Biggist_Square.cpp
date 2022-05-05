#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int ver_max = board.size();
    int hor_max = board[0].size();

    //i = 세로 , j = 가로
    for(int i = 1 ; i < ver_max ; i++)
    {
        for(int j = 1 ; j < hor_max ; j++)
        {
            if(board[i][j] == 1)
            {
                int temp = min(board[i-1][j], board[i][j-1]);
                temp = min(temp, board[i-1][j-1]) + 1;
                board[i][j] = temp;
                if(answer < temp * temp) answer = temp * temp;
            }
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12905

/*
다이나믹 프로그래밍
1x1의 경우 : answer = board[0][0];

나머지의 경우, index를 [1,1]에서부터 확인하기 시작함
board가 1인경우에는 정사각형의 가능성이 있음
따라서 1인 경우, board에서 현 위치의 정사각형 크기의 정보를 저장함
011
111
111
정사각형의 크기를 저장하기 위해, 왼쪽 위에서 부터 확인
자기 자신의 왼쪽, 위, 왼쪽위대각선을 확인하여 작은 수를 선택, +1하여 저장
저장하면서, 그 숫자의 제곱이 answer보다 크면 answer = 숫자제곱
*/