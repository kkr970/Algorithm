#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    //bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0 ; i < phone_book.size() - 1 ; i++)
    {
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].length()))
            return false;
    }
    return true;
    //return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42577

/*
생각
1) string 2중 for문을 사용해서 접두사인가를 확인 -> 엄청난 시간을 소요할 듯
2) 정렬을 한 뒤, i, i+1을 비교하며 접두사인가를 확인 -> 작동할 것 같지만, 해시를 사용하는 방법은?
--------다른사람 풀이(해시맵 사용한 것)------
bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash_map;
    for(int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;

    for(int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }
    return answer;
}
-모든 전화번호를 해시맵에 저장하고, 전화번호를 하나씩 가져옴
가져온 전화번호를 한 글자씩 꺼내 string에 더함
string을 해시맵에 있는가를 확인, 있으면 false 반환
-생각보다 오래걸릴 것 같은데 사용해도 효율성이 통과 되는 듯 보임
*/