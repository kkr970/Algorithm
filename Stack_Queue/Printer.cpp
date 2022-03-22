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
����
location�� 0�� �Ǹ鼭, priorities[location]�� ���� ū ���� �ɶ�
while
    ���� ū ��(index�� ����)�� ã��, index�� ����
    index�� 0�� �� �� ���� �տ� ���Ҹ� �ڷ� ����(location ���ڵ� �����)
    
    if(location == 0) answer++, break;
    else �� ���� ���� ����, location - 1, answer++;
*/