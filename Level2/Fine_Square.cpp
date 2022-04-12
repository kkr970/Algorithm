using namespace std;

long long GetGCD(long long a, long long b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    long long a = w;
    long long b = h;
    long long gcd = GetGCD(a, b);

    return (a * b) - (agcd + b/gcd - 1) * gcd;
}

// https://programmers.co.kr/learn/courses/30/lessons/62048

/*
����
ū �簢�� w x h �� �밢������ �ڸ�
������ 1x1�� �簢���� ����µ� �ִ��� ���� ���ϴ� ��
8 x 12
�ִ� ����� 4
4*2 x 4*3
-> 2x3 * 4
2x3�� �������� �簢�� * 4�� ��

�������� �簢�� ���ϱ�
2x3
����
����
����

1x1
��

3x5
������
������
������
������
������

->
���� �Ʒ��� �����϶��� ���������� �̵��� ���� ����
���� ���������� �̵��ϴ� �� Ƚ�� ����-1 ����
���� �Ʒ��� �����̴� �� Ƚ�� ���� ����
�� ���� + ���� - 1 �� �ϸ� ��


*/