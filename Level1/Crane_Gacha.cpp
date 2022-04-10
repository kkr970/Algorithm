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
생각
벡터에 인형값들을 저장
0이면 패스

크레인이 인형을 뽑은것을 stack이나 벡터에 저장
top이 같은 인형일 경우, answer++, pop

*/