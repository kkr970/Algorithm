#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<vector<int>> doll_stack(board[0].size());
    vector<int> basket;

    for(int i = board.size() - 1 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j < board[i].size() ; j++)
            if(board[i][j] != 0)
                doll_stack[j].push_back(board[i][j]);
    }

    basket.push_back(0);
    for(int move : moves)
    {
        
        move--;
        if(!doll_stack[move].empty())
        {
            if(doll_stack[move].back() != basket.back())
            {
                basket.push_back(doll_stack[move].back());
                doll_stack[move].pop_back();
            }
            else
            {
                doll_stack[move].pop_back();
                basket.pop_back();
                answer += 2;
            }
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/64061

/*
����
���Ϳ� ���������� ����
0�̸� �н�

ũ������ ������ �������� stack�̳� ���Ϳ� ����
top�� ���� ������ ���, answer++, pop

*/