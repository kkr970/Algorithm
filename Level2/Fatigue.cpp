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
������ �̿��ؼ� ��� ����� ���� ���� ���� ������ ������ ���� Ȯ��
ex) ������ 4��
1234�� ������ �̿�
index 0���� ������ ����
value���� ������ ��ȣ

*/