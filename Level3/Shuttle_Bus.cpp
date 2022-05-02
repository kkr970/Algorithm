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
    //i��° ������ ������, �ð��� 540 + (i*t)
    for(int i = 0 ; i < n ; i++)
    {
        int p = 0;
        //�մ��� �¿�, �ִ� m��
        for(int j = 0 ; j < m ; j++)
        {
            if(index < minute.size() && minute[index] <= bus)
            {
                index++;
                p++;
            }
        }
        //����
        if(i == n-1)
        {
            //������ �ִ� �ο��� Ÿ���� ���� ���
            if(p < m)
            {
                answer_min = bus;
            }
            //������ �ִ� �ο��� Ÿ�ִ� ��� -> ������ �ο����� -1��
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
������ 9�ú��� ���� ����
n ���� ���� Ƚ��
t ���� ���� ������ ���� ��
m ���� �ִ� �ο�

�ִ��� �ʰ� �� �� �ִ� �ð�?

�ִ��� �ʰ� ���� ���ؼ� ������ ������ ������ Ÿ����
������ ������ Ÿ�� ���ؼ� 
�տ� ��ٸ� ����� ������ ���°��� Ȯ�� �ؾ���
������ ������ �� �ִ� �ο��� 5��, 3������, 9�ú��� 30�а��� �̶�� ����
������ �� 15���� ������ �� ����
���� ������ 10�� 30���� ������
-10�� 30�к��� ���� �� ������� ���� 15���� ���� �ʴ� ���
    ���� �ð��� ���缭 10�� 30�п� �����ϸ� ��
-10�� 30�к��� ���� �� ������� ���� 15���� �Ѵ� ���
    15�� °�� ������� 1���� ����� Ż �� ����
-> ��, ���⼭ ����� ���� ��, ���� ������ 5���ε� ���� 3�� Ÿ�� ���� ��찡 ���� ��
    �̷��� ��쿡�� Ż �� �ִ� �ο������� 5���� �����ϴ� ���� ������

*/
