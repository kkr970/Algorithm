#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());

    int temp = 0;
    for(int i : d)
    {
        if(temp + i > budget) break;
        
        temp += i;
        answer++;        
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12982

/*
부서별 필요한 금액이 들어옴
총 예산이 있음
최대로 지원해 줄 수 있는 부서의 수를 return
-> 필요한 금액을 오름차순으로 정렬하고
더하면서
예산보다 작을때 까지 계산
*/