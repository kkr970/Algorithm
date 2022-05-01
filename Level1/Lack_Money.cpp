using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    for(int i = 1 ; i <= count ; i++)
    {
        answer += price * i;
    }
    answer -= money;
    if(answer <= 0) return 0;
    else return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/82612

