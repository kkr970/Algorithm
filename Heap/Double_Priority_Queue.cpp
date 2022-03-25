#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

void maxpq_clear(priority_queue<int>& pQ)
{
	priority_queue<int> reset;
	swap(pQ, reset);
}
void minpq_clear(priority_queue<int, vector<int>, greater<int>>& pQ)
{
	priority_queue<int, vector<int>, greater<int>> reset;
	swap(pQ, reset);
}


vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(string operation : operations)
    {
        //삽입
        if(operation[0] == 'I')
        {
            int num = stoi(operation.substr(2, operation.length() - 1));
            maxHeap.push(num);
            minHeap.push(num);
        }
        //삭제
        else if(operation[0] == 'D')
        {
            //최솟값 삭제
            if(operation[2] == '-' && !minHeap.empty())
            {
                minHeap.pop();
                //숫자가 전부 지워짐
                if(maxHeap.top() < minHeap.top())
                {
                    maxpq_clear(maxHeap);
                    minpq_clear(minHeap);
                }
            }
            //최댓값 삭제
            else if(!maxHeap.empty())
            {
                maxHeap.pop();
                //숫자가 전부 지워짐
                if(maxHeap.top() < minHeap.top())
                {
                    maxpq_clear(maxHeap);
                    minpq_clear(minHeap);
                }
            }
        }
    }
    
    if( (maxHeap.empty() || minHeap.empty()) )
        return {0, 0};
    else if( maxHeap.top() < minHeap.top() )
        return {0, 0};
    else
        return {maxHeap.top(), minHeap.top()};
}
// https://programmers.co.kr/learn/courses/30/lessons/42628

/*
생각
우선순위 큐를 사용

I  숫자     -> 큐에 삽입
D  1        -> 최댓값 삭제 
D -1        -> 최솟값 삭제

빈 큐에 삭제 명령어는 무시

빈큐로 끝나면 0, 0 return

-------다른사람 풀이-------
-set을 사용해서 풀었음
set은 중복이 허용되지 않으며, 자동으로 정렬이 되어짐
그 중 multiset은 중복이 허용이 됨, 자동으로 정렬이 되어짐 -> 이를 사용하여 간단하게 풀이함

#include <set>

using namespace std;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que;
    multiset<int>::iterator iter;
    string sub;

    for(auto s : arguments) {
        sub =s.substr(0, 2);
        if(sub=="I ") que.insert(stoi(s.substr(2,s.length()-2))); 
        else if(s.substr(2,1)=="1"&&que.size()>0) { que.erase(--que.end()); }
        else if(que.size()>0) { que.erase(que.begin()); }
    }

    if(que.size()==0) { answer.push_back(0); answer.push_back(0); }
    else { 
        iter = --que.end(); answer.push_back(*iter); 
        iter = que.begin(); answer.push_back(*iter);
    }

    return answer;
}
*/