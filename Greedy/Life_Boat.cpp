#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int front = 0;
    int end = people.size() - 1;

    sort(people.begin(), people.end());
    while(front <= end)
    {
        answer++;
        if(front == end) break;
        if(people[front] + people[end] <= limit)
        {
            front++;
            end--;
        }
        else
            end--;
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42885
/*
����
����Ʈ�� �ִ� 2��ۿ� ��Ž
���� ������ 2���� �������� ������ �����

1) ������ �̿�, ���ſ���, ���������� �Ѹ� ��

    �ݺ��� 1���� answer++;
    index�� 0~19 �̸� front�� 0�������� 1�� ����, end�� 19�������� 1�� ����
    ������ ����� �Ѹ��� ���, �Ѹ� ����
    vec[front] + vec[end] <= limit�� ���, �θ� �� ����
        �ƴҰ�� �Ѹ� ����
            ����� ����� front�� ��� front++

            //����� ����� end�� ��� end++
            -> ����� ����� �����԰� ���� ����̸� �� ��������� �� ���ſ� ����� ����
                �׷��� �Ǹ� ���ſ��� + 2������ ���������� ������ limit�� �ѱ� �� �ۿ� ����
                ���� front�� �����ϴ� ���� ����

    front >= end �� �Ǵ� ����(��� ���� ����) return


*/