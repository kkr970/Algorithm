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
string�� stack�� �־ Ȯ��
��ȣ�� ������ [] () {} �� ����

1) ���� ��ȣ - ���ÿ� push
2) �ݴ� ��ȣ - ������ top�� ���� ���� ��ȣ�� �־�� ��
                ���� ��ȣ�� �ƴϰų� ���� ���, �ùٸ� ��ȣ�� �ƴ�
3) string�� ���� �ϳ��� ���� ��� - ������ �� ���, answer++
4) stack�� ���
5) string�� ȸ�� -�����ϴ� index�� +1�� ����, length�� �Ѿ�� 0���� ����
-�� ������ �ݺ�
*/