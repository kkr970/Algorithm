#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = (w * 2) + 1;
    
    vector<pair<int, int>> reach_vec; // 인덱스 시작, 끝
    
    for(int station : stations)
    {
        reach_vec.push_back(make_pair(station - w, station + w));
    }
    
    int pre_right = 0;
    for(pair<int, int> reach : reach_vec)
    {
        if(reach.first - pre_right < 2)
        {
            pre_right = reach.second;
            continue;
        }
        int temp = reach.first - pre_right - 1;

        answer += temp/range;
        if(temp%range != 0) answer++;
        
        pre_right = reach.second;
    }
    if(n - pre_right > 0)
    {
        int temp = n - pre_right;
        answer += temp/range;
        if(temp%range != 0) answer++;
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12979

/*
전파 범위에 대해 저장 - range (좌, 우, 가운데를 포함한 전체 범위)
모든 기지국에 대해서 전파가 닿는 곳을 저장
전파가 닿지 않는 범위 unreached를 알아냄
unreached / range를 이용해 내부에 기지국이 들어갈 갯수 answer += 갯수
마지막 N 노드 까지도 범위가 닿는지 검사하여 기지국 수를 더함
*/