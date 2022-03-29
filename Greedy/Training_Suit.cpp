#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int* suit = new int[n+1]{0};

    for(int temp : lost)
        suit[temp]--;
    for(int temp : reserve)
        suit[temp]++;

    for(int i = 1 ; i < n ; i++)
    {
        if(suit[i] == 0)
            continue;

        else if(suit[i] == -1)
        {
            if(suit[i - 1] == 1)
            {
                suit[i] = 0;
                suit[i - 1] = 0;
            }
            else if(suit[i + 1] == 1)
            {
                suit[i] = 0;
                suit[i + 1] = 0;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
        if(suit[i] == -1)
            answer--;

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42862

/*
����
answer == ��ü �л���

��ü �л� ��Ȳ�� ����
�Ҿ� ���� �л��� -1
������ �л��� +1

for(int i = 1 ; i < n ; i++ )
    i��  0 continue
    i�� -1�̸� i-1, i+1�� ���� 1�ΰ� ã�� �Ѵ� 0���� ����

�迭���� -1��ŭ answer���� ��




*/