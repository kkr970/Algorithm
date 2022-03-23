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
생각
큐를 사용
반복마다 시간을 + 1
반복
{
    3) 다리 위에 있는 트럭이 다리에 얼마나 머물렀는지 확인
        3-1) bridge_length < 맨 앞차의 머문 시간
            다리는 건너는 트럭 맨 앞에 제거
        3-2) bridge_length > 맨 앞차의 머문 시간
            대기
    1) 현재 다리에 있는 트럭이 가진 무게의 합 < weight
        대기 트럭에서 1개를 꺼내 다리에 올림
    2) 현재 다리에 있는 트럭이 가진 무게의 합 > weight
        무게 0의 트럭을 올림

    경과시간 + 1
    다리 위에 머문 시간 전체 + 1
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
