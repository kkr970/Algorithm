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
생각
문자열이 연결되어 같은 문자가 있는 경우, 두 문자를 제거 -> 반복
모든 문자열이 제거되면 1
문자열이 남으면 0

->
스택을 이용해서 top과 같으면 pop
문자열 끝까지 반복
스택이 비어있으면 1
아니면 0 반환
*/