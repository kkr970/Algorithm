#include <string>
#include <vector>
#include <queue>

using namespace std;

int max_num_index(vector<int> v)
{
    int num = 0;
    int index = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] > num)
        {
            index = i;
            num = v[i];
        }
    }
    return index;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    while(!priorities.empty())
    {
        int index = max_num_index(priorities);
        for(int i = 0 ; i < index ; i ++)
        {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            if(location != 0)
                location--;
            else
                location = priorities.size() - 1;
        }
        if(location == 0)
        {
            answer++;
            break;
        }
        else
        {
            priorities.erase(priorities.begin());
            location--;
            answer++;
        }
    }
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42587

/*
생각
location이 0이 되면서, priorities[location]이 가장 큰 수가 될때
while
    가장 큰 수(index가 빠른)를 찾고, index를 구함
    index가 0이 될 때 까지 앞에 원소를 뒤로 보냄(location 숫자도 변경됨)
    
    if(location == 0) answer++, break;
    else 맨 앞의 숫자 제거, location - 1, answer++;
*/