#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

int down(vector<char> vec, int i, int max)
{
    bool goDown = true;
    int cur = i;

    if(i != max)
        i++;
    else
    {
        i--;
        goDown = false;
    }

    while(vec[i] == 'X')
    {
        if(goDown)
        {
            i++;
            if(i == max)
            {
                goDown = false;
                i = cur - 1;
            }
        }
        else
        {
            i--;
        }
    }
    return i;
}
int up(vector<char> vec, int i)
{
    bool goUp = true;
    int cur = i;

    if(i != 0)
        i--;
    else
    {
        i++;
        goUp = false;
    }

    while(vec[i] == 'X')
    {
        if(goUp)
        {
            i--;
            if(i == 0)
            {
                goUp = false;
                i = cur + 1;
            }
        }
        else
        {
            i++;
        }
    }
    return i;
}

string solution(int n, int k, vector<string> cmds) {
    string answer = "";
    vector<char> answer_vec(n, 'O');
    stack<int> deleted;

    for(string cmd : cmds)
    {
        char command = cmd[0];
        switch (command)
        {
        case 'D':
            for(int i = 0 ; i < cmd[2] - '0' ; i++)
                k = down(answer_vec, k, n);
            break;
        case 'U':
            for(int i = 0 ; i < cmd[2] - '0' ; i++)
                k = up(answer_vec, k);
            break;
        case 'C':
            answer_vec[k] = 'X';
            deleted.push(k);
            k = down(answer_vec, k, n-1);
            break;
        case 'Z':
            int index = deleted.top();
            deleted.pop();
            answer_vec[index] = 'O';
            break;
        }
    }
    for(char c : answer_vec)
        answer += c;
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/81303

/*
n : 표의 전체 수
k : 현재 선택된 위치
cmd : 명령 string

명령에는 D x, U x, C, Z가 있음
D x : x칸만큼 아래로 이동
U x : x칸만큼 위로 이동
C : 현재 선택되어진 칸을 삭제, 이후 선택되어지는 칸은 아랫칸 (마지막일경우, 윗칸)
Z : 가장 최근에 지웠던 데이터 복구

stack을 이용해 C가 명령되어진 index를 순서대로 push
Z가 나오는 경우, stack에서 pop, 이것을 true로 변경

*/