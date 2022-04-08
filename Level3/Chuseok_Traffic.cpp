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
����
��� �ð��� ���ؼ� ��û�� ������ �����ϴ� ���� ��ȿ�� ����

���۽ð�, ����ð��� �������� Ȯ���ؾ� �� ��

��� ���۽ð� , ����ð� �� ������ ���͸� ���� vec<pair<int, int> -> �ð��� �ʷ� ����
�� : �� : �� .xxx
(�� * 3600 + �� * 60 + ��)*1000 + xxx

1�� ������ �� ��
1�� ������ �� ��
�պ��� �ڿ� �ִ� ����ð�
�ں��� �տ� �ִ� ���۽ð�
�Ѵ� �����ϴ� ��û�� ���� ó����

��� ��û �ð��� ������ �ð��� �������� ���ĵǾ� ����
for(int i = vec.size() ; i >= 0 ; i--) // ������ ���������� ����
    int num = 0; // ��û��
    int a = vec[i][1]; ����ð�, ������ ��
    for(int j = i  ; j >= 0 ; j--  )
        if(a <= vec[j][0] <= a+999) num++;
        else if(a <= vec[j][1] <= a+999) num++;
        else break; //�Ѵ� �ƴϸ� break;
    if(answer < num) answer = num;



*/