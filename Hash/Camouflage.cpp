#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> clothes_map;
    
    for(vector<string> temp : clothes)
        clothes_map[temp[1]]++;

    for(auto temp : clothes_map)
        answer *= (temp.second + 1);
    
    return answer - 1;
}


// https://programmers.co.kr/learn/courses/30/lessons/42578

/*
생각
1) 해시테이블에 저장, key가 얼굴은1, 상의는2, 하의는3, 겉옷은4
    해당하는 종류가 나타나면 value를 + 1
    모든 옷들의 조합을 이용
    입지 않는 경우를 제외하면 됨
    ex)2개/ 1개/ 1개/ 1개
    얼굴 : x, 1, 2 -> 3개의 가능성
    상의 : x, 1 -> 2개의 가능성
    하의 : x, 1 -> 2개의 가능성
    겉옷 : x, 1 -> 2개의 가능성
    모든 조합 : 3 * 2 * 2 * 2 = 24개
    옷을 입지 않는 경우는 제외 -> 24 - 1 = 23
    
2) 해시테이블을 사용하지 않아도 array에 {얼굴, 상의, 하의, 겉옷}
    순서로 저장해서 사용해도 좋을 듯
    그래도 해시를 사용해서 풀기위해 해시를 사용함

배워가는 점
map에 insert할 때, 없는 key값에 key를 조작하려고 할 때,
없는 key값일 경우 int는 0으로 넣어줌
*/