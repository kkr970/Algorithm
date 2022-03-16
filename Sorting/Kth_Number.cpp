#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    //���� ��¿� ����
    vector<int> answer;
    
    for(vector<int> command : commands)
    {
        vector<int> temp;
        int left = command.at(0) - 1;
        int right = command.at(1) - 1;
        int k = command.at(2) - 1;
        
        // �迭 ����
        for(int i = left ; i <= right ; i++)
            temp.push_back(array.at(i));

        // �̾Ƴ� �迭 ����
        sort(temp.begin(), temp.end());
        
        // �迭���� k��° ��ġ�� ���� ����
        answer.push_back(temp.at(k));
    }
    
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42748