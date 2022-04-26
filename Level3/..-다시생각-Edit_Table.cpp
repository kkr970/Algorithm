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
n : ǥ�� ��ü ��
k : ���� ���õ� ��ġ
cmd : ��� string

��ɿ��� D x, U x, C, Z�� ����
D x : xĭ��ŭ �Ʒ��� �̵�
U x : xĭ��ŭ ���� �̵�
C : ���� ���õǾ��� ĭ�� ����, ���� ���õǾ����� ĭ�� �Ʒ�ĭ (�������ϰ��, ��ĭ)
Z : ���� �ֱٿ� ������ ������ ����

stack�� �̿��� C�� ��ɵǾ��� index�� ������� push
Z�� ������ ���, stack���� pop, �̰��� true�� ����

*/