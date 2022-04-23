#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> count = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};

    int temp = 0;
    for(int i = 0 ; i < a ; i++)
        temp += count[i];
    temp += b;

    answer = day[(temp - 1) % 7];
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12901

/*
2016년은 윤년
1년이 366일임
1월 1일이 금요일
{SUN, MON, TUE, WED, THU, FRI, SAT}
a는 월
b는 일
1 31
2 29
3 31
4 30
5 31
6 30
7 31
8 31
9 30
10 31
11 30
12 31

*/