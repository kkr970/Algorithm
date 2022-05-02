#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int answer_min = 0;
    vector<int> minute;

    sort(timetable.begin(), timetable.end());
    for(string temp : timetable)
    {
        int m = stoi(temp.substr(0, 2))*60 + stoi(temp.substr(3));
        minute.push_back(m);
    }

    int last_bus = 540 + ((n - 1) * t);
    int max_p = n * m;

    int bus = 540;
    int index = 0;
    //i번째 버스가 도착함, 시간은 540 + (i*t)
    for(int i = 0 ; i < n ; i++)
    {
        int p = 0;
        //손님을 태움, 최대 m명
        for(int j = 0 ; j < m ; j++)
        {
            if(index < minute.size() && minute[index] <= bus)
            {
                index++;
                p++;
            }
        }
        //막차
        if(i == n-1)
        {
            //막차에 최대 인원이 타있지 않은 경우
            if(p < m)
            {
                answer_min = bus;
            }
            //막차에 최대 인원이 타있는 경우 -> 마지막 인원보다 -1분
            else
            {
                answer_min = minute[index-1] - 1;
            }
            break;
        }
        bus += t;
    }
    
    string a = to_string(answer_min/60);
    string b = to_string(answer_min%60);
    
    if(a.length() == 1) a = '0' + a;
    if(b.length() == 1) b = '0' + b;
    answer = a + ':' + b;

    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/17678

/*
버스는 9시부터 운행 시작
n 버스 운행 횟수
t 간격 마다 버스는 새로 옴
m 버스 최대 인원

최대한 늦게 갈 수 있는 시간?

최대한 늦게 가기 위해선 무조건 마지막 버스를 타야함
마지막 버스를 타기 위해서 
앞에 기다린 사람이 버스에 탔는가를 확인 해야함
버스아 수용할 수 있는 인원이 5명, 3번오고, 9시부터 30분간격 이라고 가정
버스는 총 15명을 수용할 수 있음
또한 버스는 10시 30분이 막차임
-10시 30분보다 빨리 온 사람들의 수가 15명이 넘지 않는 경우
    버스 시간에 맞춰서 10시 30분에 도착하면 됨
-10시 30분보다 빨리 온 사람들의 수가 15명이 넘는 경우
    15등 째의 사람보다 1분이 빨라야 탈 수 있음
-> 단, 여기서 등수를 정할 때, 버스 정원이 5명인데 비해 3명만 타고 가는 경우가 있을 것
    이러한 경우에도 탈 수 있는 인원수에서 5명을 제외하는 것이 적절함

*/
