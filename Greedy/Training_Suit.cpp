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
생각
answer == 전체 학생수

전체 학생 현황을 만듬
잃어 버린 학생은 -1
여분의 학생은 +1

for(int i = 1 ; i < n ; i++ )
    i가  0 continue
    i가 -1이면 i-1, i+1을 봐서 1인걸 찾아 둘다 0으로 변경

배열에서 -1만큼 answer에서 뺌




*/