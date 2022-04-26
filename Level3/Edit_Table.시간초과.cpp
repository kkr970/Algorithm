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

*/