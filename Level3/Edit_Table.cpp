#include <string>
#include <vector>

struct Node
{
    bool isDelete;
    Node* prev;
    Node* next;
};

Node table[1000000];

using namespace std;

string solution(int n, int k, vector<string> cmds) {
    string answer(n, 'O');
    vector<Node*> deleted;
    int move = 0;

    for(int i = 1 ; i < n ; i++)
    {
        table[i-1].next = &table[i];
        table[i].prev = &table[i-1];
    }
    
    Node* cur = &table[k];

    for(string cmd : cmds)
    {
        if(cmd[0] == 'U')
        {
            move = stoi(cmd.substr(2));
            while(move--)
                cur = cur->prev;
        }
        else if(cmd[0] == 'D')
        {
            move = stoi(cmd.substr(2));
            while(move--)
                cur = cur->next;
        }
        else if(cmd[0] == 'C')
        {
            deleted.push_back(cur);
            cur->isDelete = true;
            Node* prev = cur->prev;
            Node* next = cur->next;
            if(prev)
                prev->next = next;
            if(next)
            {
                next->prev = prev;
                cur = next;
            }
            else
                cur = prev;
            
        }
        else //if(cmd[0] == 'Z')
        {
            Node* node = deleted.back();
            deleted.pop_back();
            node->isDelete = false;

            Node* prev = node->prev;
            Node* next = node->next;
            if(prev)
                prev->next = node;
            if(next)
                next->prev = node;
        }
    }

    for(int i = 0 ; i < n ; i++)
        if(table[i].isDelete) answer[i] = 'X';

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

//map을 쓴 경우 - 효율성 9, 10번 통과 안됨---------------------------------------------------------
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(int n, int k, vector<string> cmds) {
    string answer(n, 'O');
    vector<int> deleted;
    int move = 0;
    int redo = 0;

    unordered_map<int, pair<int, int>> ll;
    pair<int, int> link;

    for(int i = 0 ; i < n-1 ; i++)
        ll[i] = make_pair(i-1, i+1);
    ll[n-1] = make_pair(n-2, -1);
    
    for(string cmd : cmds)
    {
        if(cmd[0] == 'U' || cmd[0] == 'D')
        {
            move = stoi(cmd.substr(2));
            if(cmd[0] == 'U')
                while(move--)
                    k = ll[k].first;
            else
                while(move--)
                    k = ll[k].second;

        }
        else if(cmd[0] == 'C')
        {
            deleted.push_back(k);
            link = ll[k];
            ll[link.first].second = link.second;
            ll[link.second].first = link.first;
            if(link.second != -1) k = link.second;
            else k = link.first;
        }
        else if(cmd[0] == 'Z')
        {
            redo = deleted.back();
            deleted.pop_back();
            link = ll[redo];
            ll[link.first].second = redo;
            ll[link.second].first = redo;
        }
    }

    for(int num : deleted)
        answer[num] = 'X';

    return answer;
}
//set을 쓴 경우 - 효율성 전부 통과 안됨---------------------------------------------------------------------
#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(int n, int k, vector<string> cmds) {
    string answer(n, 'O');
    vector<int> deleted;
    int move = 0;
    int redo = 0;

    set<int> table;
    for(int i = 0 ; i < n ; i++)
        table.insert(i);
    set<int>::iterator cur = table.find(k);

    for(string cmd : cmds)
    {
        if(cmd[0] == 'U')
        {
            move = stoi(cmd.substr(2));
            while(move--)
                cur = prev(cur);
        }
        else if(cmd[0] == 'D')
        {
            move = stoi(cmd.substr(2));
            while(move--)
                cur = next(cur);
        }
        else if(cmd[0] == 'C')
        {
            deleted.push_back(*cur);
            cur = table.erase(cur);
            if(cur == table.end()) cur = prev(cur);
        }
        else if(cmd[0] == 'Z')
        {
            table.insert(deleted.back());
            deleted.pop_back();
        }
    }

    for(int num : deleted)
        answer[num] = 'X';

    return answer;
}

*/