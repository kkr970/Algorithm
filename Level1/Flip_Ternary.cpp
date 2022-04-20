#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    string temp = "";
    do
    {
        int remainder = n % 3;
        n /= 3;
        temp += to_string(remainder);
    }while(n != 0);
    
    int three = 1;
    for(int i = temp.length()-1 ; i >= 0 ; i--)
    {
        answer += (temp[i] - '0')*three;
        three *= 3;
    }


// https://programmers.co.kr/learn/courses/30/lessons/68935

/*
자연수를 3진법으로 변경
3진법을 반전시켜서 10진법으로 표현하면 됨
45 -> 1200 -> 0021 -> 7

*/