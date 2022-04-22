#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> num_set;
    sort(numbers.begin(), numbers.end());

    for(int i = 0 ; i < numbers.size() - 1 ; i++)
    {
        for(int j = i + 1 ; j < numbers.size() ; j++)
        {
            int temp = numbers[i] + numbers[j];
            num_set.insert(temp);
        }
    }
    for(int num : num_set)
    {
        answer.push_back(num);
    }
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/68644

/*
배열에 있는 숫자들 중 2개를 뽑아 더함
중복x

*/