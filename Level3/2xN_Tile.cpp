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
세로2, 가로N 인 큰 틀이 있음
타일은 가로2, 세로1

타일을 가로로 쌓으면 2칸을 차지함
타일을 세로로 쌓으면 1칸을 차지함
2와 1의 조합으로 N을 만들 수 있으면 됨

->피보나치 수열로 해결이 가능함
112358
n이 1인 경우 1
n이 2인 경우 2
*/