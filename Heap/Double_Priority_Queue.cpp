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
        //����
        if(operation[0] == 'I')
        {
            int num = stoi(operation.substr(2, operation.length() - 1));
            maxHeap.push(num);
            minHeap.push(num);
        }
        //����
        else if(operation[0] == 'D')
        {
            //�ּڰ� ����
            if(operation[2] == '-' && !minHeap.empty())
            {
                minHeap.pop();
                //���ڰ� ���� ������
                if(maxHeap.top() < minHeap.top())
                {
                    maxpq_clear(maxHeap);
                    minpq_clear(minHeap);
                }
            }
            //�ִ� ����
            else if(!maxHeap.empty())
            {
                maxHeap.pop();
                //���ڰ� ���� ������
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
����
�켱���� ť�� ���

I  ����     -> ť�� ����
D  1        -> �ִ� ���� 
D -1        -> �ּڰ� ����

�� ť�� ���� ��ɾ�� ����

��ť�� ������ 0, 0 return

-------�ٸ���� Ǯ��-------
-set�� ����ؼ� Ǯ����
set�� �ߺ��� ������ ������, �ڵ����� ������ �Ǿ���
�� �� multiset�� �ߺ��� ����� ��, �ڵ����� ������ �Ǿ��� -> �̸� ����Ͽ� �����ϰ� Ǯ����

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