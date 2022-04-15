#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, float> a, pair<int, float> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> failure;
    int player_num = stages.size();

    sort(stages.begin(), stages.end());
    stages.push_back(999);

    int flag = 0;
    int pre_fail = 0;
    int reach = 0;
    int fail = 0;
    //스테이지
    for(int s = 1 ; s <= N ; s++)
    {
        int i = flag;
        for( ; i < player_num ; i++)
            if(stages[i] >= s)
            {
                reach = player_num - i;
                break;
            }
        for( ; i < player_num+1 ; i++)
            if(stages[i] > s)
            {
                flag = i;
                fail = i - pre_fail;
                pre_fail = i;
                break;
            }
        failure.push_back(make_pair(s, (float)fail / reach));
        
        cout << "stage : " << s << "\n";
        cout << "reach : " << reach << "\n";
        cout << "fail : " << fail << "\n";
        cout << "pre_fail : " << pre_fail << "\n";
        cout << "flag : " << flag << "\n\n";
    }

    sort(failure.begin(), failure.end(), cmp);
    for(pair<int, float> temp : failure)
    {
        cout << temp.first << " : " << temp.second << "\n";
    }
    for(pair<int, float> temp : failure)
    {
        answer.push_back(temp.first);
    }

    return answer;
}

int main(){

    vector<int> temp;
    temp.push_back(2);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(6);
    temp.push_back(4);
    temp.push_back(3);
    temp.push_back(3);
    

    cout << endl;
    temp = solution(5, temp);


    return 0;
}

// https://programmers.co.kr/learn/courses/30/lessons/42889

/*
생각
스테이지에 도달했으나, 클리어하지 못한 플레이어 수 / 스테이지에 도달한 플레이어 수
실패율이 높은 스테이지부터 내림차순

stage에 머물러 있다는 것은 스테이지를 클리어하지 못했다는 의미
즉, 3스테이지 상태라면 1, 2는 클리어, 3은 클리어 못함

[2, 1, 2, 6, 2, 4, 3, 3] 오름차순 정렬
[1, 2, 2, 2, 3, 3, 4, 6]
1스테이지에 도달한 사람 -> 8
2스테이지에 도달한 사람 -> 7
3스테이지에 도달한 사람 -> 4
4스테이지에 도달한 사람 -> 2
5스테이지에 도달한 사람 -> 1
6스테이지에 도달한 사람 -> 1

*/
