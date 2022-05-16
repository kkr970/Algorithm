#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    unordered_map<string, int> dictionary;
    
    int num = 1;
    int round = 1;
    string pre_word = "";
    bool isFail = false;
    for(string word : words)
    {
        dictionary[word]++;
        if(num == 1 && round == 1)
        {
            pre_word = word;
            num++;
            continue;
        }

        if(dictionary[word] > 1 || pre_word[pre_word.length() - 1] != word[0])
            return {num, round};

        pre_word = word;
        num++;
        if(num > n)
        {
            num = 1;
            round++;
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12981

/*
1) map에 word를 저장하며 중복을 확인
2) 끝 char와 첫 char가 같은지 확인

*/