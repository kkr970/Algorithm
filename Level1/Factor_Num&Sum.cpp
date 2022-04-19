#include <string>
#include <vector>

using namespace std;

//����� ¦���ΰ� �Ǻ�
bool isEven(int num)
{
    bool even = true;
    for(int i = 1 ; i <= num ; i++)
        if(num%i == 0)
            even = !even;
    return even;
}

int solution(int left, int right) {
    int answer = 0;

    for(int i = left ; i <= right ; i++)
    {
        if(isEven(i)) answer += i;
        else answer -= i;
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/77884

/*
����
���� 2���� �־���
������ ������ ������ ���� ��
����� ���� ¦���� ���� ���ϰ� Ȧ���� ���� ��
*/