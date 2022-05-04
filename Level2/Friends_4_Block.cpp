#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    set<pair<int, int>> delete_block; // <i, j>

    do
    {
        delete_block.clear();

        //i m : 높이, 세로    j n : 폭, 가로
        for(int i = 0 ; i < m-1 ; i++)
        {
            for(int j = 0 ; j < n-1 ; j++)
            {
                char cur = board[i][j];
                if(cur == '1') continue;
                if(cur == board[i+1][j] && cur == board[i][j+1] && cur == board[i+1][j+1])
                {
                    delete_block.insert(make_pair(i, j));
                    delete_block.insert(make_pair(i+1, j));
                    delete_block.insert(make_pair(i, j+1));
                    delete_block.insert(make_pair(i+1, j+1));
                }
            }
        }
        if(!delete_block.empty())
        {
            answer += delete_block.size();
            for(pair<int, int> temp : delete_block)
            {
                board[temp.first][temp.second] = '1';
            }
            for(int j = 0 ; j < n ; j++)
            {
                int height = 0;
                bool flag = false;
                for(int i = m-1 ; i >= 0 ; i--)
                {
                    if(board[i][j] == '1')
                    {
                        height++;
                        flag = true;
                    }
                    if(flag && board[i][j] != '1')
                    {
                        char c = board[i][j];
                        board[i][j] = board[i+height][j];
                        board[i+height][j] = c;
                    }
                }
            }
        }
    }while(!delete_block.empty());
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/17679

/*
각 블록이 2x2의 형태로 4개가 만나면
지워지는 블록 갯수를 answer에 더함

블록을 확인, i+1, j+1, i+1 j+1 즉, 오른쪽, 아래쪽, 대각선 3개를 확인하여
동일한 블록일 경우 answer++, 벡터에 위치를 저장함
모든 블록을 살펴보고 벡터가 비어있다면 지워지는 블록이 없기에 return answer
벡터가 비지 않았다면, 벡터에 해당하는 블록을 지우고, 위에 있는 블록을 아래로 정렬시켜야함
AABC
22BC
11BC
BCAA 일 경우, 숫자가 지워지는 블록이라고 가정하면, AA는 아래로 2칸씩 이동해야 할 것임
-> 각 열의 숫자의 높이를 계산하여 숫자보다 위에 있는 블록에 한해 i+(1의 높이)와 교체함
즉, i=0에 있는 A들은 0+2 = 2, i=2에 있는 같은 열에 블록과 교체를 함
11BC
22BC
AABC
BCAA
가 될 것임
-> 여기서 숫자를 다른것을 사용했으나, 이는 위치를 보여주기 위함이고 사실 똑같은 숫자를 사용하면 됨
    (블록은 A~Z를 사용함)
-> 아래서 부터 진행을 하며, A~Z가 아닐 경우, 높이를 +1를 해줌, A~Z를 만날 경우, 높이만큼 i를 더하면
    중간에 여러 그룹의 블록이 지워져도 작동함

*/
