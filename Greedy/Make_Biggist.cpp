#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for(int i = 0 ; i < number.length() ; i++)
    {
        if(k != 0 && answer != "" && answer[answer.length() - 1] < number[i])
        {
            answer = answer.substr(0, answer.length() - 1);
            k--;
            i--;
            continue;
        }
        if(k != 0 && number[i] < number[i + 1])
        {
            k--;
            continue;
        }
        answer += number[i];
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42883

/*
생각
1)string에서 값을 하나씩 확인
    k가 0인경우 멈춤
    만약 자기 자신보다 다음 숫자가 큰 경우, 자기 자신을 삭제 k--

2)string에서 값을 하나씩 확인
    answer에 들어간 숫자가 자기 자신보다 작은 경우, answer에 값 삭제, k--
    값을 answer에 넣는데, 다음 숫자가 자기보다 큰 경우, continue, k--
    단 k가 0인 경우, continue는 일어나지 않음
    
2번을 사용하는게 좋을듯


*/