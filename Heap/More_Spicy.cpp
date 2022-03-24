#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pQ;

    for(int temp : scoville)
        pQ.push(temp);

    while(!pQ.empty())
    {
        int t = pQ.top();
        pQ.pop();
        
        if(t >= K) break;
        else
        {
            if(pQ.empty()) return -1;
            int second = pQ.top();
            pQ.pop();
            pQ.push( t + (second * 2) );
            answer++;
        }
    }
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42626

/*
생각
우선수위 큐를 사용
가장 작은 수를 꺼내 K와 비교
1) k보다 작으면 가장 작은 수를 꺼내 a + b*2 를 계산, 힙에 삽입, answer++
2) k보다 크면 끝

*/