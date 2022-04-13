#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> c_stack;

    for(char c : s)
    {
        if(!c_stack.empty() && c_stack.top() == c)
            c_stack.pop();
        else
            c_stack.push(c);
    }

    if(c_stack.empty())
        answer = 1;
    else
        answer = 0;

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12973

/*
����
���ڿ��� ����Ǿ� ���� ���ڰ� �ִ� ���, �� ���ڸ� ���� -> �ݺ�
��� ���ڿ��� ���ŵǸ� 1
���ڿ��� ������ 0

->
������ �̿��ؼ� top�� ������ pop
���ڿ� ������ �ݺ�
������ ��������� 1
�ƴϸ� 0 ��ȯ
*/