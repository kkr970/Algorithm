int solution(int n, int a, int b)
{
    int answer = 0;
    while(a != b)
    {
        a = (a+1)/2;
        b = (b+1)/2;
        answer++;
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12985

/*
경기는 토너먼트로 진행
만약 8명에서 진행하면
1-2 3-4 5-6 7-8 의 경기 진행
이후
1-2 -> 1
3-4 -> 2
5-6 -> 3
7-8 -> 4
로 변경
1-2 3-4 진행
1-2 진행
우승

N=총인원
A, B가 몇라운드에서 만나는지?
ex_ 8, 4, 7
4번과 7번은 만나기 전까지 항상 우승한다고 가정돼어 있음

4+1 / 2 = 2
7+1 / 2 = 4

2+1 / 2 = 1
4+1 / 2 = 2

1+1 / 2 = 1
2+1 / 2 = 1 ->만남

즉, 각 선수의 번호에 (a+1)/2를 진행, answer++
번호가 같아지는 순간 answer을 리턴

*/