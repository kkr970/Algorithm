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
�� ���ڿ��� ����
���ڿ��� 2���ھ� ��� �ߺ��� ����ϴ� set���� ����
ex) abcd -> ab, bc, cd

( (str1, str2�� �������� ��) / (str1, str2�� �������� ��) ) * 65536 �� �ϸ� ��
-��, str1, str2�� set�� ��� �������� ��� 1 * 65536���� ó��
*/