#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for(long long number : numbers)
    {
        if(number % 2 == 0)
        {
            answer.push_back(number+1);
        }
        else // 홀수인 경우 가장 우측의 0비트를 찾아야함
        {
            long long zero = 1;
            while(true)
            {
                if(number & zero == 0) break;
                zero *= 2;
            }
            zero /= 2;
            answer.push_back(number + zero);
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/77885

/*
비트가 1~2개 다른 수 중 가장 작은 값을 return

long long이기 때문에 비트를 하나씩 확인하는 것은 문제가 있음

규칙1 짝수
2 = 10
4 = 100
6 = 110
8 = 1000
...
가장 마지막 비트는 0이 됨, 따라서 +1를 해주게 된다면
비트는 1개가 다를 것이고
가장 작은 수가 될 것

규칙2 홀수
1 = 1
3 = 11
5 = 101
7 = 111
9 = 1001
...
가장 마지막 비트가 1, 따라서 +1을 하게되면 비트가 올림이 됨
7 = 111
111 + 1 = 1000
0111 1000은 4개나 다른 비트가 되기에 +1하는 것은 옳바르지 않음

0111
1000
1001
1010
1011 -> 2개 차이로 제일 작은 수, 11

01011 - 11
01100
01101 -> 2개 차이로 제일 작은 수 - 13
-> 가장 오른쪽에 있는 0을 한칸 오른쪽으로 이동시키면 됨
    이는 오른쪽에 있는 0보다 한칸 오른쪽의 값을 더해주면 됨
    1011에서는 10(1)1 이 숫자가 될 것이고
    1011 + 10 = 1101이 됨
    0

1011 11
1101 13

비트연산 공부
or, |   같은 자리의 비트가 둘 중 하나라도 1인경우 1
and, &  같은 자리의 비트가 둘다 1인 경우 1
xor, ^  같은 자리의 비트가 둘 중 하나만 1인 경우 1
<< >> , 비트 1칸 이동

*/