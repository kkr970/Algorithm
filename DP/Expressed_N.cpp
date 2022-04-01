#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;

    vector<unordered_set<int>> DP(8);

    int temp = 0;
    for(int i = 0 ; i < 8 ; i++)
    {
        temp = temp * 10 + N;
        DP[i].insert(temp);
    }

    for(int i = 1 ; i < 8 ; i++)
    {
        int a = 0;
        int b = i-1;
        for( ; a < i ; a++, b--)
        {
            for(int a_num : DP[a])
            {
                for(int b_num : DP[b])
                {
                    DP[i].insert(a_num + b_num);
                    //�ʿ���� �� ���� (����, 0�϶��� ����)
                    if(a_num - b_num > 0)
                        DP[i].insert(a_num - b_num);
                    DP[i].insert(a_num * b_num);
                    //�ʿ���� �� ���� (0 ����)
                    if(a_num / b_num > 0)
                        DP[i].insert(a_num / b_num);
                }
            }
        }
        if(DP[i].count(number) == 1)
            return i + 1;
    }

    return -1;
}

// https://programmers.co.kr/learn/courses/30/lessons/42895

/*
����
-�ּڰ��� 8���� ũ�� return -1;
    ->��� Ƚ���� 8������ ���
-�����⿡�� �������� ���� -> int���

���⼭ ��ǥ number�� ���
�����ؾ� �ϴ� ��
    1. 0 -> 0���� ���������� ������ ���� ���� 0�� ���ϴ� ���ڸ� ����µ� ������ ���� ����
    2. ������ -> - ���꿡 ���� ������ �������� ����� ������ �ٲٸ� ��ȣ�� �ٲ� �� ����, ���� ���꿡 ���� ����� �������� ����
    3. �ߺ��� -> �Ȱ��� ���ڴ� �ʿ䰡 ���� set�� �̿��ؼ� �ذ�

������ �����Ѵٰ� �����ϰ�
1�� �̿��� ���

1�� ���
1

2�� ���
11
(1�����-1�����)

3�� ���
111
(1��-2��) 2������ 1-1�� ������
(2��-1��)

4�� ���
1111
(1��-3��)
(2��-2��)
(3��-1��)

5�� ���
11111
(1-4)
(2-3)
(3-2)
(4-1)

n�� ���
1n
(1 - n-1)
(2 - n-2)
...
(n-1 - 1)
*/