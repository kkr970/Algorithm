#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

struct qcmp{
    bool operator() (vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};

bool jobcmp(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int time_remaining = 0;
    int jobs_num = jobs.size();
    bool isWorking = false;

    vector<int> cur_job;
    priority_queue<vector<int>, vector<vector<int>>, qcmp> pQ;
    
    sort(jobs.begin(), jobs.end(), jobcmp);

    for(vector<int> job : jobs)
    {
        for(int i : job)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    do
    {
        //작업을 대기목록에 추가
        if(!jobs.empty())
        {
            int temp = 0;
            for(int i = 0 ; i < jobs.size() ; i++)
            {
                if(jobs[i][0] == time)
                {
                    cout << "push! add job list!\n" ;
                    pQ.push(jobs[i]);
                    temp++;
                }
            }
            jobs.erase(jobs.begin(), jobs.begin() + temp);
        }

        if(isWorking)
        {
            //일 진행
            cout << "remain : " << --time_remaining << "\n";
            //일이 끝남
            if(time_remaining == 0)
            {
                cout << "end job!\n";
                isWorking = false;
                cout << "working time : " << time - cur_job[0] << "\n";
                answer += time - cur_job[0];
                cur_job.clear();
            }
        }
        //아무것도 안하고 있을 때, 다음 작업 시작시간을 기다림
        if(!isWorking)
        {
            if(!pQ.empty() && pQ.top()[0] <= time)
            {
                isWorking = true;
                cur_job = pQ.top();
                time_remaining = cur_job[1];
                pQ.pop();
                cout << "pop! start job!\n";
                cout << "job : " << cur_job[0] << " " << cur_job[1] << "\n";
            }
        }

        cout << "time : " << time << "\n";
        cout << "queue size : " << pQ.size() << "\n";
        cout << "job size : " << jobs.size() << "\n";
        cout << "cur_job : " << cur_job.size() << "\n";
        if(isWorking) cout << "working!\n\n";
        else cout << "sleeping...\n\n";
        time++; 
    }while( !(pQ.empty() && jobs.empty() && cur_job.empty()) );    

    return answer / jobs_num;
}

int main(){
    vector<vector<int>> jobs;
    jobs.push_back({24, 10});
    jobs.push_back({28, 39});
    jobs.push_back({43, 20});
    jobs.push_back({37, 5});
    jobs.push_back({47, 22});
    jobs.push_back({20, 47});
    jobs.push_back({15, 34});
    jobs.push_back({15, 2});
    jobs.push_back({35, 43});
    jobs.push_back({26, 1});

    cout << "answer : " << solution(jobs);

    return 0;
}

// https://programmers.co.kr/learn/courses/30/lessons/42627

/*
생각
반복문을 사용해서 1반복에 1ms라고 생각
queue : 작업 대기

1ms가 지날 때 마다 생각해야 할 것
-jobs.begin().first가 진행된 시간과 같으면, queue에 삽입
-일하고 있지 않으면 queue에서 맨 앞에 있는 작업을 가져옴
-일이 끝나면 queue에서 맨 앞에 있는 작업을 가져옴
    -queue에서 가져올 일이 없으며, jobs가 비었을 경우 break
    -일이 끝난 시점에서 answer += time - 일을 요청한 시간
-time++

return answer/jobs.size


*/