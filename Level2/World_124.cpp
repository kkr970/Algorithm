#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    do
    {
        int remainder = n % 3;
        n /= 3;
        if(remainder == 0)
        {
            n -= 1;
            remainder = 4;
        }
        answer = to_string(remainder) + answer;
    }while(n != 0);

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12899

/*
���� 3���� ����
1 -> ������ 1
2 -> ������ 2
3 -> ��1 ������ 0
4 -> ��1 ������ 1
5 -> ��1 ������ 2
6 -> ��2 ������ 0
7 -> ��2 ������ 1
...
20 -> �� 6 ������ 2 -> (��2 ������ 0)(������ 2)

3�� ���, �������� 0�� ��쿡 4�� ���;� ��
��, ���� 1�� ���� �������� 4�� �����ϸ� ��
*/