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
����
1) string 2�� for���� ����ؼ� ���λ��ΰ��� Ȯ�� -> ��û�� �ð��� �ҿ��� ��
2) ������ �� ��, i, i+1�� ���ϸ� ���λ��ΰ��� Ȯ�� -> �۵��� �� ������, �ؽø� ����ϴ� �����?
--------�ٸ���� Ǯ��(�ؽø� ����� ��)------
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
-��� ��ȭ��ȣ�� �ؽøʿ� �����ϰ�, ��ȭ��ȣ�� �ϳ��� ������
������ ��ȭ��ȣ�� �� ���ھ� ���� string�� ����
string�� �ؽøʿ� �ִ°��� Ȯ��, ������ false ��ȯ
-�������� �����ɸ� �� ������ ����ص� ȿ������ ��� �Ǵ� �� ����
*/