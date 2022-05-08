#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = s.length()/2;

    if(s.length() % 2 == 1)
        answer += s[index];
    else
        answer += s.substr(index-1, 2);

        return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12903
