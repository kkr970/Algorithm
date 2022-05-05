#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int ver_max = board.size();
    int hor_max = board[0].size();

    //i = ���� , j = ����
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
���̳��� ���α׷���
1x1�� ��� : answer = board[0][0];

�������� ���, index�� [1,1]�������� Ȯ���ϱ� ������
board�� 1�ΰ�쿡�� ���簢���� ���ɼ��� ����
���� 1�� ���, board���� �� ��ġ�� ���簢�� ũ���� ������ ������
011
111
111
���簢���� ũ�⸦ �����ϱ� ����, ���� ������ ���� Ȯ��
�ڱ� �ڽ��� ����, ��, �������밢���� Ȯ���Ͽ� ���� ���� ����, +1�Ͽ� ����
�����ϸ鼭, �� ������ ������ answer���� ũ�� answer = ��������
*/