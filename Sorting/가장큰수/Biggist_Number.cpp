#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(int i : numbers)
        temp.push_back(to_string(i));
    
    sort(temp.begin(), temp.end(), cmp);

    if(temp.at(0) == "0")
        return "0";
    for(string str : temp)
        answer += str;
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42746?language=cpp

/*
공부해야 할점 sort 함수에 대해서
sort(i, j)
보통 벡터i ~ 벡터j까지 오름차순으로 정렬해줌
i < j가 참, 비교함수가 참이라 swap이 일어나지 않음

sort(i, j, func)
func에 비교 함수가 들어가는데, 자동으로 i, j가 첫번째, 두번째 매개변수로 입력됨
func가 참이면 swap이 일어나지 않음
위에 cmp 함수에서 a + b > b + a인데
a가 1,  b가 2  순서가 바뀌어야 함
12 > 21 은 거짓임으로 swap이 일어남
그러면 i, j의 순서가 바뀌기 때문에 숫자가 큰 b가 앞으로 오게 됨
*/