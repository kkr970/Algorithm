#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0 ; i < prices.size(); i++)
    {
        for(int j = i + 1 ; j < prices.size() ; j++)
        {
            if(prices[i] > prices[j])
            {
                answer.push_back(j - i);
                break;
            }
            if(j == prices.size() - 1)
            {
                answer.push_back(j - i);
                break;
            }
        }
    }
    answer.push_back(0);
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42584

/*
생각
자신의 값보다 낮아지는 index를 찾음
낮아지는 index - 자신의index를 저장

-------스텍을 이용한 방법------
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}
*/