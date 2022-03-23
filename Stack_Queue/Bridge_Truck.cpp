#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int weight_sum(vector<pair<int, int>> weights)
{
    int sum = 0;
    for(int i = 0 ; i < weights.size() ; i++)
        sum += weights[i].first;
    return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<pair<int, int>> trucks;


    while(!truck_weights.empty() || !trucks.empty())
    {
        if(!trucks.empty())
        {
            if(trucks[0].second > bridge_length)
            {
                trucks.erase(trucks.begin());
            }
        }

        if(!truck_weights.empty())
        {
            if( !(trucks.size() >= bridge_length) && weight_sum(trucks) + truck_weights[0] <= weight )
            {
                trucks.push_back(make_pair(truck_weights[0], 1));
                truck_weights.erase(truck_weights.begin());
            }
        }

        answer++;
        for(int i = 0 ; i < trucks.size() ; i++)
        {
            trucks[i].second++;
        }
    }

    return answer;
}


// https://programmers.co.kr/learn/courses/30/lessons/42583

/*
����
ť�� ���
�ݺ����� �ð��� + 1
�ݺ�
{
    3) �ٸ� ���� �ִ� Ʈ���� �ٸ��� �󸶳� �ӹ������� Ȯ��
        3-1) bridge_length < �� ������ �ӹ� �ð�
            �ٸ��� �ǳʴ� Ʈ�� �� �տ� ����
        3-2) bridge_length > �� ������ �ӹ� �ð�
            ���
    1) ���� �ٸ��� �ִ� Ʈ���� ���� ������ �� < weight
        ��� Ʈ������ 1���� ���� �ٸ��� �ø�
    2) ���� �ٸ��� �ִ� Ʈ���� ���� ������ �� > weight
        ���� 0�� Ʈ���� �ø�

    ����ð� + 1
    �ٸ� ���� �ӹ� �ð� ��ü + 1
}

7, 4, 5, 6

7_
_7
4_
54
_5
6_
_6
__

*/
