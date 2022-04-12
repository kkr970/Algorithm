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
생각
큰 사각형 w x h 을 대각선으로 자름
나머지 1x1인 사각형을 만드는데 최대의 수를 구하는 것
8 x 12
최대 공약수 4
4*2 x 4*3
-> 2x3 * 4
2x3에 버려지는 사각형 * 4가 됨

버려지는 사각형 구하기
2x3
ㄴㅁ
ㄴㄴ
ㅁㄴ

1x1
ㄴ

3x5
ㄴㅁㅁ
ㄴㄴㅁ
ㅁㄴㅁ
ㅁㄴㄴ
ㅁㅁㄴ

->
ㄴ이 아래로 움직일때와 오른쪽으로 이동할 때가 있음
ㄴ이 오른쪽으로 이동하는 총 횟순 가로-1 번임
ㄴ이 아래로 움직이는 총 횟순 새로 번임
즉 가로 + 세로 - 1 을 하면 됨


*/