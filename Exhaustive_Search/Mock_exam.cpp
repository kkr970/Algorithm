#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> score = {0, 0, 0};
    int maxScore = 0;

    for(int i = 0 ; i < answers.size() ; i++)
    {
        if(answers[i] == one[i % one.size()])
            score[0]++;
        if(answers[i] == two[i % two.size()])
            score[1]++;
        if(answers[i] == three[i % three.size()])
            score[2]++;
    }
    
    maxScore = *max_element(score.begin(), score.end());
    for(int i = 0 ; i < score.size() ; i++)
        if(score[i] == maxScore)
            answer.push_back(i+1);
    
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42840

// 딱히 어려운점은 없었음