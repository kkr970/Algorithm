#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same = 0;
    int zero = 0;

    for(int lotto : lottos)
    {
        if(lotto == 0)
        {
            zero++;
            continue;
        }

        for(int i = 0 ; i < 6 ; i++)
        {
            if(lotto == win_nums[i])
            {
                same++;
                break;
            }
        }
    }

    int max = 7-same-zero;
    if(max < 6)
        answer.push_back(max);
    else
        answer.push_back(6);
    
    int min = 7-same;
    if(min < 6)
        answer.push_back(min);
    else
        answer.push_back(6);

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/77484#fn1

/*
����
int same = lottos�� win_nums�� ���� ���Ҹ� ���� ��
int zero = lottos�� ���� 0�� ��

same + zero�� �ִ�� ���� �� �ִ� ���� ��
same �� �ּҷ� ���� �� �ִ� ���� ��

7 - ���� �� �� ������ ������
7 - ���� �� �� 6���� ū ���, ������ 6��
return [�ִ� ���� ���� ����, �ּҷ� ���� ���� ����]
*/