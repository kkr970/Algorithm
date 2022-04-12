#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> isExist(10);

    for(int number : numbers)
        isExist[number] = true;

    for(int i = 0 ; i < 10 ; i++)
        if(!isExist[i])
            answer += i;

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/86051

/*
배열에 0~9 중 없는 수를 다 더함

-또는 0~9를 다 더한 45에서 존재하는 수를 빼도 됨
*/