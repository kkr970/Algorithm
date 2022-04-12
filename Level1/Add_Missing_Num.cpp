#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> isExist(10);

    for(int number : numbers)
        isExist[number] = true;

    for(int i = 0 ; i < 10 ; i++)
        if(!isExist[i])
            answer += i;

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/86051

/*
�迭�� 0~9 �� ���� ���� �� ����

-�Ǵ� 0~9�� �� ���� 45���� �����ϴ� ���� ���� ��
*/