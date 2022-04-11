#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<char> names;

int GetIndex(char c)
{
    for(int i = 0 ; i < 8 ; i++)
        if(names[i] == c)
            return i;
    return -1;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    names = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    do{
        bool check = false;
        for(string condition : data)
        {
            if(check) break;

            int me = GetIndex(condition[0]);
            int you = GetIndex(condition[2]);
            char operation = condition[3];
            int distance = condition[4] - '0';

            if(operation == '<' && abs(me - you) - 1 >= distance)
                check = true;
            else if(operation == '>' && abs(me - you) - 1 <= distance)
                check = true;
            else if(operation == '=' && abs(me - you) - 1 != distance)
                check = true;
        }
        if(!check) answer++;
	}while(next_permutation(names.begin(), names.end()));

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/1835

/*
생각
맴버 : {A, C, F, J, M, N, R, T} // 오름차순으로 정렬 되어 있음
next_permutation 을 사용해서 모든 경우의 수를 확인할 수 있음

모든 경우마다 data를 읽어 조건을 만족하는지 확인
    모두 만족하면 answer++

data
0 = 나
1 = ~
2 = 상대
3 = <, >, =
4 = 거리(나, 상대 사이에 있는 친구들 수)
    나, 상대 사이의 거리는 abs(나.index - 상대.index - 1)
*/
