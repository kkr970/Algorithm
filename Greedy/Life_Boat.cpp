#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int front = 0;
    int end = people.size() - 1;

    sort(people.begin(), people.end());
    while(front <= end)
    {
        answer++;
        if(front == end) break;
        if(people[front] + people[end] <= limit)
        {
            front++;
            end--;
        }
        else
            end--;
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42885
/*
생각
구명보트는 최대 2명밖에 못탐
무게 제한은 2명의 몸무게의 합으로 계산함

1) 정렬을 이용, 무거운사람, 가벼운사람을 한명씩 봄

    반복문 1번당 answer++;
    index가 0~19 이면 front는 0에서부터 1씩 증가, end는 19에서부터 1씩 감소
    구출할 사람이 한명인 경우, 한명 구출
    vec[front] + vec[end] <= limit일 경우, 두명 다 구출
        아닐경우 한명만 구출
            구출된 사람이 front일 경우 front++

            //구출된 사람이 end일 경우 end++
            -> 구출된 사람이 몸무게가 작은 사람이면 그 다음사람은 더 무거운 사람일 것임
                그렇게 되면 무거운사람 + 2번쨰로 가벼운사람은 무조건 limit을 넘길 수 밖에 없음
                따라서 front을 구출하는 것이 맞음

    front >= end 가 되는 순간(모두 구한 순간) return


*/