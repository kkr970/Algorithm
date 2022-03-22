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
생각
progresses, speeds를 각 index로 비교해서 새로운 arr생성
arr에는 완성되는 기간이 써있음
ex {5, 3, 7}
arr을 0부터 확인
처음에 만난 5보다 작은 수를 만나면 temp++
i보다 큰 수를 만나면 answer.push_back(temp)
다시 i = 7, 7보다 큰수를 만날 때 까지 temp++
끝날 때 까지 반복

큐, 스텍을 사용해서는 어떻게 구현 하는가
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