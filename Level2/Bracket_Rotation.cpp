#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<char> stack;

    for(int i = 0 ; i < s.length() ; i++)
    {
        int index = i;
        int j = 0;
        for( ; j < s.length() ; j++)
        {
            if(s[index] == '[' || s[index] == '{' || s[index] == '(')
            {
                stack.push_back(s[index]);
            }
            else if(s[index] == ']')
            {
                if(!stack.empty() && stack.back() == '[')
                {
                    stack.pop_back();
                }
                else
                    break;
            }
            else if(s[index] == '}')
            {
                if(!stack.empty() && stack.back() == '{')
                {
                    stack.pop_back();
                }
                else
                    break;
            }
            else if(s[index] == ')')
            {
                if(!stack.empty() && stack.back() == '(')
                {
                    stack.pop_back();
                }
                else
                    break;
            }
            index = (index + 1) % s.length();
        }
        if(j == s.length() && stack.size() == 0) answer++;
        stack.clear();
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/76502

/*
string을 stack에 넣어서 확인
괄호의 종류는 [] () {} 가 있음

1) 여는 괄호 - 스택에 push
2) 닫는 괄호 - 스택의 top에 같은 쌍의 괄호가 있어야 함
                같은 괄호가 아니거나 없는 경우, 올바른 괄호가 아님
3) string을 전부 하나씩 넣은 경우 - 스택이 빈 경우, answer++
4) stack을 비움
5) string을 회전 -시작하는 index를 +1씩 조정, length를 넘어가면 0으로 변경
-이 과정을 반복
*/