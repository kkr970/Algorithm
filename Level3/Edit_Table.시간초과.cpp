#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmds) {
    string answer = "";
    stack<int> deleted;

    unordered_map<int, pair<int, int>> ll;
    int right = 0;
    int left = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(i == 0)
            ll[i] = make_pair(-1, i+1);
        else if(i == n-1)
            ll[i] = make_pair(i-1, -1);
        else
            ll[i] = make_pair(i-1, i+1);
    }
    
    for(string cmd : cmds)
    {
        switch(cmd[0])
        {
        case 'U':
            for(int i = 0 ; i < stoi(cmd.substr(2)) ; i++)
            {
                k = ll[k].first;
            }
            break;
        case 'D':
            for(int i = 0 ; i < stoi(cmd.substr(2)) ; i++)
            {
                k = ll[k].second;
            }
            break;
        case 'C':
            deleted.push(k);

            left = ll[k].first;
            right = ll[k].second;
            ll[left].second = ll[k].second;
            ll[right].first = ll[k].first;

            if(ll[k].second != -1) k = ll[k].second;
            else k = ll[k].first;
            break;
        case 'Z':
            int redo = deleted.top();
            deleted.pop();

            left = ll[redo].first;
            right = ll[redo].second;
            ll[left].second = redo;
            ll[right].first = redo;
            break;
        }
    }
    
    vector<char> check(n, 'O');
    while(!deleted.empty())
    {
        check[deleted.top()] = 'X';
        deleted.pop();
    }
    for(char c : check)
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

-------연결리스트를 이용--------
left = k.first
right = k.second

U, D : 방향으로 횟수만큼 이동

C : 왼쪽과 오른쪽을 서로 연결 시켜줌, 자기 자신은 냅둠(나중에 redo할 수도 있기 때문)
    left.second = k.second
    right.first = k.first
    k = k.second (단, k.second가 -1인 경우, first 선택)
    stack.push(k)

Z : stack의 top이 가장 최근 지워진 내용이니 top을 이용, top의 왼쪽과 오른쪽을 자기 자신과 연결
    redo = stack.top()
    left = redo.first
    right = redo.second
    left.second = redo
    right.first = redo

stack을 이용해 C가 명령되어진 index를 순서대로 push
Z가 나오는 경우, stack에서 pop, 이것을 true로 변경

*/