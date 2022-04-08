#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> time_vec;

    for(string line : lines)
    {
        int hour = stoi( line.substr(11, 2) );
        int min = stoi( line.substr(14, 2) );
        int sec = stoi( line.substr(17, 2) );
        int msec = stoi( line.substr(20, 3) );
        string temp = "";
        for(int i = 24 ; i < line.length() ; i++)
        {
            if(line[i] == 's') break;
            if(line[i] != '.')
                temp += line[i];
        }
        while(temp.size() < 4)
            temp += '0';
        int p = stoi(temp);

        int time = (hour*3600 + min*60 + sec)*1000 + msec;
        time_vec.push_back(make_pair(time - p + 1, time));
    }

    for(int i = time_vec.size() - 1 ; i >= 0 ; i--)
    {
        int num = 0;
        int a = time_vec[i].second;
        int b = a + 999;
        for(int j = i ; j < time_vec.size() ; j++)
        {
            if( a <= time_vec[j].second && b >= time_vec[j].first)
                num++;
            else
                continue;
        }
        if(answer < num) answer = num;
    }

    return answer;
}

//  https://programmers.co.kr/learn/courses/30/lessons/17676

/*
생각
모든 시간에 대해서 요청의 개수를 저장하는 것은 비효율 적임

시작시간, 종료시간을 기준으로 확인해야 할 듯

모든 시작시간 , 종료시간 을 저장한 벡터를 생성 vec<pair<int, int> -> 시간을 초로 변경
시 : 분 : 초 .xxx
(시 * 3600 + 분 * 60 + 초)*1000 + xxx

1초 간격의 맨 앞
1초 간격의 맨 뒤
앞보다 뒤에 있는 종료시간
뒤보다 앞에 있는 시작시간
둘다 만족하는 요청의 수가 처리량

모든 요청 시간은 끝나는 시간을 기준으로 정렬되어 있음
for(int i = vec.size() ; i >= 0 ; i--) // 벡터의 마지막에서 부터
    int num = 0; // 요청수
    int a = vec[i][1]; 종료시간, 간격의 앞
    for(int j = i  ; j >= 0 ; j--  )
        if(a <= vec[j][0] <= a+999) num++;
        else if(a <= vec[j][1] <= a+999) num++;
        else break; //둘다 아니면 break;
    if(answer < num) answer = num;



*/