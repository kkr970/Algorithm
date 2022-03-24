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
����
�켱���� ť�� ���
���� ���� ���� ���� K�� ��
1) k���� ������ ���� ���� ���� ���� a + b*2 �� ���, ���� ����, answer++
2) k���� ũ�� ��

*/