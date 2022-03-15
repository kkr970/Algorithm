#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int index = 0;

    sort(citations.rbegin(), citations.rend());

    for(index = 0 ; index < citations.size(); index++)
        if(index + 1 >= citations.at(index))
            break;

    if(index == citations.size())
        return citations.size();
    else if(index == 0)
        return 0;
    else
    {
        for(int i = citations.at(index - 1) ; i > citations.at(index) ; i--)
        {
            if(index == i)
                return i;
        }
        return citations.at(index);
    }
    return -1;
}

// https://programmers.co.kr/learn/courses/30/lessons/42747

/* 생각

논문의 인용 횟수가 들어있는 배열이 있음
오름차순으로 정렬하게 된다면 [index]보다 큰 수는 전부 뒤에 있음
또는, 내림차순으로 정렬하게 된다면 [index]보다 큰 수는 전부 앞에 있음
index+1은 arr[index]번 이상 인용된 논문의 수
index + 1 >= h = arr[index]
ex) [1, 4, 4, 0, 5, 2] -> [5, 4, 4, 2, 1, 0]
-> index 3에서 나옴
4~2 사이의 값 중 h를 만족하는 h를 찾기

[6, 5, 3, 1, 0]
-> index 2 에서 나옴
5~3 사이의 값 중 만족하는 큰 값을 찾기

[0, 0, 0, 0, 0]
-> index가 0에서 나옴

*/
