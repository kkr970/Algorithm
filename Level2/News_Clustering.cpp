#include <string>
#include <algorithm>
#include <set>
#include <cctype>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> set1;
    multiset<string> set2;

    for(int i = 0 ; i < str1.length() - 1 ; i++)
    {
        if(!isalpha(str1[i]) || !isalpha(str1[i+1])) continue;
        string temp = "";
        temp += tolower(str1[i]);
        temp += tolower(str1[i+1]);
        set1.insert(temp);
    }
    for(int i = 0 ; i < str2.length() - 1 ; i++)
    {
        if(!isalpha(str2[i]) || !isalpha(str2[i+1])) continue;
        string temp = "";
        temp += tolower(str2[i]);
        temp += tolower(str2[i+1]);
        set2.insert(temp);
    }

    for(string s : set1)
        cout << s << " ";
    cout << "\n";
    for(string s : set2)
        cout << s << " ";
    cout << "\n";

    multiset<string> a;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(a, a.begin()));

    multiset<string> b;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(b, b.begin()));

    for(string s : a)
        cout << s << " ";
    cout << "\n";

    for(string s : b)
        cout << s << " ";
    cout << "\n";

    if(a.size() != 0)
        answer = (int)( (float)b.size()/a.size() * 65536 );
    else
        answer = 65536;
    
    return answer;
}

int main(){

    cout << solution("FRANCE", "french");
    //solution("handshake", "shake hand");

    return 0;
}

// https://programmers.co.kr/learn/courses/30/lessons/17677

/*
두 문자열이 들어옴
문자열을 2문자씩 끊어서 중복을 허용하는 set으로 생성
ex) abcd -> ab, bc, cd

( (str1, str2의 교집합의 수) / (str1, str2의 합집합의 수) ) * 65536 을 하면 됨
-단, str1, str2의 set이 모두 공집합일 경우 1 * 65536으로 처리
*/