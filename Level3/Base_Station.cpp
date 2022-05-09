#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = (w * 2) + 1;
    
    vector<pair<int, int>> reach_vec; // �ε��� ����, ��
    
    for(int station : stations)
    {
        reach_vec.push_back(make_pair(station - w, station + w));
    }
    
    int pre_right = 0;
    for(pair<int, int> reach : reach_vec)
    {
        if(reach.first - pre_right < 2)
        {
            pre_right = reach.second;
            continue;
        }
        int temp = reach.first - pre_right - 1;

        answer += temp/range;
        if(temp%range != 0) answer++;
        
        pre_right = reach.second;
    }
    if(n - pre_right > 0)
    {
        int temp = n - pre_right;
        answer += temp/range;
        if(temp%range != 0) answer++;
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12979

/*
���� ������ ���� ���� - range (��, ��, ����� ������ ��ü ����)
��� �������� ���ؼ� ���İ� ��� ���� ����
���İ� ���� �ʴ� ���� unreached�� �˾Ƴ�
unreached / range�� �̿��� ���ο� �������� �� ���� answer += ����
������ N ��� ������ ������ ����� �˻��Ͽ� ������ ���� ����
*/