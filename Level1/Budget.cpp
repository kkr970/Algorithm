#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());

    int temp = 0;
    for(int i : d)
    {
        if(temp + i > budget) break;
        
        temp += i;
        answer++;        
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12982

/*
�μ��� �ʿ��� �ݾ��� ����
�� ������ ����
�ִ�� ������ �� �� �ִ� �μ��� ���� return
-> �ʿ��� �ݾ��� ������������ �����ϰ�
���ϸ鼭
���꺸�� ������ ���� ���
*/