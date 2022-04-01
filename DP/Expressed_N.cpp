#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;

    vector<unordered_set<int>> DP(8);

    int temp = 0;
    for(int i = 0 ; i < 8 ; i++)
    {
        temp = temp * 10 + N;
        DP[i].insert(temp);
    }

    for(int i = 1 ; i < 8 ; i++)
    {
        int a = 0;
        int b = i-1;
        for( ; a < i ; a++, b--)
        {
            for(int a_num : DP[a])
            {
                for(int b_num : DP[b])
                {
                    DP[i].insert(a_num + b_num);
                    //필요없는 수 제거 (음수, 0일때도 제거)
                    if(a_num - b_num > 0)
                        DP[i].insert(a_num - b_num);
                    DP[i].insert(a_num * b_num);
                    //필요없는 수 제거 (0 제거)
                    if(a_num / b_num > 0)
                        DP[i].insert(a_num / b_num);
                }
            }
        }
        if(DP[i].count(number) == 1)
            return i + 1;
    }

    return -1;
}

// https://programmers.co.kr/learn/courses/30/lessons/42895

/*
생각
-최솟값이 8보다 크면 return -1;
    ->사용 횟수가 8까지만 계산
-나누기에서 나머지는 무시 -> int사용

여기서 목표 number은 양수
제외해야 하는 값
    1. 0 -> 0으로 나눠버리는 문제가 생김 또한 0은 원하는 숫자를 만드는데 도움이 되지 않음
    2. 음수값 -> - 연산에 의해 나오는 값이지만 계산의 순서를 바꾸면 부호를 바꿀 수 있음, 이후 연산에 같은 결과를 가져오기 때문
    3. 중복값 -> 똑같은 숫자는 필요가 없음 set을 이용해서 해결

뺄셈만 생각한다고 가정하고
1을 이용해 계산

1번 사용
1

2번 사용
11
(1번사용-1번사용)

3번 사용
111
(1번-2번) 2번에는 1-1이 들어가있음
(2번-1번)

4번 사용
1111
(1번-3번)
(2번-2번)
(3번-1번)

5번 사용
11111
(1-4)
(2-3)
(3-2)
(4-1)

n번 사용
1n
(1 - n-1)
(2 - n-2)
...
(n-1 - 1)
*/