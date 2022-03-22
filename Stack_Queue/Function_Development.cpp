#include <string>
#include <vector>
#include <cmath>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int temp_day = ceil( (float)(100 - progresses[0]) / speeds[0] );
    int temp_answer = 1;
    
    for(int i = 1 ; i < progresses.size() ; i++)
    {
        int day = ceil( (float)(100 - progresses[i]) / speeds[i] );
        if(temp_day >= day)
            temp_answer++;
        else
        {
            answer.push_back(temp_answer);
            temp_answer = 1;
            temp_day = day;
        }
    }
    answer.push_back(temp_answer);

    return answer;
}


//https://programmers.co.kr/learn/courses/30/lessons/42586

/*
����
progresses, speeds�� �� index�� ���ؼ� ���ο� arr����
arr���� �ϼ��Ǵ� �Ⱓ�� ������
ex {5, 3, 7}
arr�� 0���� Ȯ��
ó���� ���� 5���� ���� ���� ������ temp++
i���� ū ���� ������ answer.push_back(temp)
�ٽ� i = 7, 7���� ū���� ���� �� ���� temp++
���� �� ���� �ݺ�

ť, ������ ����ؼ��� ��� ���� �ϴ°�
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;

    for(int i = 0; i < progresses.size(); i++) {
        int temp = (100-progresses[i]) % speeds[i];
        if(temp == 0)
            q.push((100-progresses[i]) / speeds[i]);
        else
            q.push((100-progresses[i]) / speeds[i] + 1);
    }

    while(!q.empty()) {
        int cnt = 1;
        int cur = q.front();
        q.pop();

        while(cur >= q.front() && !q.empty()) {
            q.pop();
            cnt++;
        }

        answer.push_back(cnt);
    }
    

*/