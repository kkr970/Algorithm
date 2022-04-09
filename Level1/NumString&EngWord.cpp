#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    string answer = "";
    unordered_map<string, char> numString_map = {
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'},
        {"zero", '0'}
    };

    string temp = "";
    for(char c : s)
    {
        if('0' <= c && c <= '9')
        {
            answer += c;
        }
        else
        {
            temp += c;
            if(numString_map.find(temp) != numString_map.end())
            {
                answer += numString_map[temp];
                temp = "";
            }
        }
    }

    return stoi(answer);
}

// https://programmers.co.kr/learn/courses/30/lessons/81301

/*
생각
영어단어와 숫자가 섞인 string을 숫자로 변경하는 내용
one - 1
two - 2
three - 3
four - 4
five - 5
six - 6
seven - 7
eight - 8
nine - 9
zero - 0

*/