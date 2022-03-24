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
        //�۾��� ����Ͽ� �߰�
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
            //�� ����
            cout << "remain : " << --time_remaining << "\n";
            //���� ����
            if(time_remaining == 0)
            {
                cout << "end job!\n";
                isWorking = false;
                cout << "working time : " << time - cur_job[0] << "\n";
                answer += time - cur_job[0];
                cur_job.clear();
            }
        }
        //�ƹ��͵� ���ϰ� ���� ��, ���� �۾� ���۽ð��� ��ٸ�
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
����
�ݺ����� ����ؼ� 1�ݺ��� 1ms��� ����
queue : �۾� ���

1ms�� ���� �� ���� �����ؾ� �� ��
-jobs.begin().first�� ����� �ð��� ������, queue�� ����
-���ϰ� ���� ������ queue���� �� �տ� �ִ� �۾��� ������
-���� ������ queue���� �� �տ� �ִ� �۾��� ������
    -queue���� ������ ���� ������, jobs�� ����� ��� break
    -���� ���� �������� answer += time - ���� ��û�� �ð�
-time++

return answer/jobs.size


*/