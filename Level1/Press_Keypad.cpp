#include <string>
#include <vector>
#include <cmath>

using namespace std;

int distance(int number, int hand)
{
    number--;
    int horizontal = abs(number/3 - hand/3);
    int vertical = abs(number%3 - hand%3);

    return horizontal + vertical;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 9;
    int right = 11;

    for(int number : numbers)
    {
        if(number == 1 || number == 4 || number == 7)
        {
            left = number - 1;
            answer += 'L';
        }
        else if(number == 3 || number == 6 || number == 9)
        {
            right = number - 1;
            answer += 'R';
        }
        else // number == 2, 5, 8, 0
        {
            if(number == 0) number = 11;
            if(distance(number, left) < distance(number, right))
            {
                left = number - 1;
                answer += 'L';
            }
            else if(distance(number, left) > distance(number, right))
            {
                right = number - 1;
                answer += 'R';
            }
            else
            {
                if(hand == "left")
                {
                    left = number - 1;
                    answer += 'L';
                }
                else
                {
                    right = number - 1;
                    answer += 'R';
                }
            }
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/67256

/*
������ ���ǿ� �ش��ϴ� ���� �ڵ�� ��ȯ�ϸ� ��

1. �ϳ��� �հ����� ���, �հ����� ������ *, #
2. 1, 4, 7�� �޼�
3. 3, 6, 9 �� ������
4. 2 5 8 0 �� ����� �հ���
5. �հ����� �Ÿ��� ������ ����������, �޼����̿� �ش��ϴ� �հ��� ���
*/
