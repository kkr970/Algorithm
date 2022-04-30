#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    vector<int> order;
    for(int i = 0 ; i < dungeons.size() ; i++)
        order.push_back(i);
    
    int fatigue;
    int num;
    do
    {
        fatigue = k;
        num = 0;
        for(int i = 0 ; i < dungeons.size() ; i++)
        {
            if(fatigue >= dungeons[order[i]][0])
            {
                fatigue -= dungeons[order[i]][1];
                num++;
            }
            else
                break;
        }
        if(answer < num) answer = num;
    } while (next_permutation(order.begin(), order.end()));
    
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/87946

/*
순열을 이용해서 모든 경우의 수에 대해 입장 가능한 던전의 수를 확인
ex) 던전이 4개
1234의 순열을 이용
index 0부터 던전에 입장
value값은 던전의 번호

*/