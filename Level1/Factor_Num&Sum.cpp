#include <string>
#include <vector>

using namespace std;

//약수가 짝수인가 판별
bool isEven(int num)
{
    bool even = true;
    for(int i = 1 ; i <= num ; i++)
        if(num%i == 0)
            even = !even;
    return even;
}

int solution(int left, int right) {
    int answer = 0;

    for(int i = left ; i <= right ; i++)
    {
        if(isEven(i)) answer += i;
        else answer -= i;
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/77884

/*
생각
정수 2개가 주어짐
정수를 포함한 사이의 수들 중
약수의 수가 짝수인 수는 더하고 홀수인 수는 뺌
*/