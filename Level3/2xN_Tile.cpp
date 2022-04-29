using namespace std;

int solution(int n) {
    int num[60001];
    
    num[0] = 1;
    num[1] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        num[i] = (num[i-1] + num[i-2])%1000000007;
    }
    
    return num[n];
}

// https://programmers.co.kr/learn/courses/30/lessons/12900

/*
����2, ����N �� ū Ʋ�� ����
Ÿ���� ����2, ����1

Ÿ���� ���η� ������ 2ĭ�� ������
Ÿ���� ���η� ������ 1ĭ�� ������
2�� 1�� �������� N�� ���� �� ������ ��

->�Ǻ���ġ ������ �ذ��� ������
112358
n�� 1�� ��� 1
n�� 2�� ��� 2
*/