#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for(int i = 0 ; i < number.length() ; i++)
    {
        if(k != 0 && answer != "" && answer[answer.length() - 1] < number[i])
        {
            answer = answer.substr(0, answer.length() - 1);
            k--;
            i--;
            continue;
        }
        if(k != 0 && number[i] < number[i + 1])
        {
            k--;
            continue;
        }
        answer += number[i];
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42883

/*
����
1)string���� ���� �ϳ��� Ȯ��
    k�� 0�ΰ�� ����
    ���� �ڱ� �ڽź��� ���� ���ڰ� ū ���, �ڱ� �ڽ��� ���� k--

2)string���� ���� �ϳ��� Ȯ��
    answer�� �� ���ڰ� �ڱ� �ڽź��� ���� ���, answer�� �� ����, k--
    ���� answer�� �ִµ�, ���� ���ڰ� �ڱ⺸�� ū ���, continue, k--
    �� k�� 0�� ���, continue�� �Ͼ�� ����
    
2���� ����ϴ°� ������


*/