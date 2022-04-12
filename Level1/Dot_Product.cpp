#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for(int i = 0 ; i < a.size() ; i++)
    {
        answer += (a[i] * b[i]);
    }
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/70128

/*
내적
두 배열을 받음
모든 원소마다 곱을하고 더하면 됨
*/