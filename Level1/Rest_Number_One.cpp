using namespace std;

int solution(int n) {
    int answer = 2;

    for( ; answer < n ; answer++)
        if( n % answer == 1) break;

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/87389

// 단순 나누기 작업