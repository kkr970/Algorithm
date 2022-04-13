#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    do
    {
        int remainder = n % 3;
        n /= 3;
        if(remainder == 0)
        {
            n -= 1;
            remainder = 4;
        }
        answer = to_string(remainder) + answer;
    }while(n != 0);

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12899

/*
전부 3으로 나눔
1 -> 나머지 1
2 -> 나머지 2
3 -> 몫1 나머지 0
4 -> 몫1 나머지 1
5 -> 몫1 나머지 2
6 -> 몫2 나머지 0
7 -> 몫2 나머지 1
...
20 -> 몫 6 나머지 2 -> (몫2 나머지 0)(나머지 2)

3의 배수, 나머지가 0인 경우에 4가 나와야 함
즉, 몫을 1을 빼고 나머지를 4로 변경하면 됨
*/