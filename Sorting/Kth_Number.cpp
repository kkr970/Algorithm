#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    //정답 출력용 벡터
    vector<int> answer;
    
    for(vector<int> command : commands)
    {
        vector<int> temp;
        int left = command.at(0) - 1;
        int right = command.at(1) - 1;
        int k = command.at(2) - 1;
        
        // 배열 추출
        for(int i = left ; i <= right ; i++)
            temp.push_back(array.at(i));

        // 뽑아낸 배열 정렬
        sort(temp.begin(), temp.end());
        
        // 배열에서 k번째 위치의 숫자 추출
        answer.push_back(temp.at(k));
    }
    
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42748