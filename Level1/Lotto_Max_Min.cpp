#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same = 0;
    int zero = 0;

    for(int lotto : lottos)
    {
        if(lotto == 0)
        {
            zero++;
            continue;
        }

        for(int i = 0 ; i < 6 ; i++)
        {
            if(lotto == win_nums[i])
            {
                same++;
                break;
            }
        }
    }

    int max = 7-same-zero;
    if(max < 6)
        answer.push_back(max);
    else
        answer.push_back(6);
    
    int min = 7-same;
    if(min < 6)
        answer.push_back(min);
    else
        answer.push_back(6);

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/77484#fn1

/*
생각
int same = lottos와 win_nums가 같은 원소를 가진 수
int zero = lottos가 가진 0의 수

same + zero는 최대로 맞출 수 있는 수가 됨
same 은 최소로 맞출 수 있는 수가 됨

7 - 맞춘 수 가 순위가 되지만
7 - 맞춘 수 가 6보다 큰 경우, 순위는 6등
return [최대 맞춘 수의 순위, 최소로 맞춘 수의 순위]
*/