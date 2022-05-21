#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int pre_num = -1;
    for(int num : arr)
    {
        if(num == pre_num) continue;
        answer.push_back(num);
        pre_num = num;
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12906