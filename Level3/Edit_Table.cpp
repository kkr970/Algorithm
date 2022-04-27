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
n : ǥ�� ��ü ��
k : ���� ���õ� ��ġ
cmd : ��� string

��ɿ��� D x, U x, C, Z�� ����
D x : xĭ��ŭ �Ʒ��� �̵�
U x : xĭ��ŭ ���� �̵�
C : ���� ���õǾ��� ĭ�� ����, ���� ���õǾ����� ĭ�� �Ʒ�ĭ (�������ϰ��, ��ĭ)
Z : ���� �ֱٿ� ������ ������ ����

-------���Ḯ��Ʈ�� �̿�--------
left = k.first
right = k.second

U, D : �������� Ƚ����ŭ �̵�

C : ���ʰ� �������� ���� ���� ������, �ڱ� �ڽ��� ����(���߿� redo�� ���� �ֱ� ����)
    left.second = k.second
    right.first = k.first
    k = k.second (��, k.second�� -1�� ���, first ����)
    stack.push(k)

Z : stack�� top�� ���� �ֱ� ������ �����̴� top�� �̿�, top�� ���ʰ� �������� �ڱ� �ڽŰ� ����
    redo = stack.top()
    left = redo.first
    right = redo.second
    left.second = redo
    right.first = redo

stack�� �̿��� C�� ��ɵǾ��� index�� ������� push
Z�� ������ ���, stack���� pop, �̰��� true�� ����

//map�� �� ��� - ȿ���� 9, 10�� ��� �ȵ�---------------------------------------------------------
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
//set�� �� ��� - ȿ���� ���� ��� �ȵ�---------------------------------------------------------------------
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