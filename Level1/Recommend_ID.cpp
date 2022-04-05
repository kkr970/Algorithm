#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    //1
    for(int i = 0 ; i < new_id.size() ; i++)
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = tolower(new_id[i]);
    
    //2, 3
    string temp = "";
    for(int i = 0 ; i < new_id.size() ; i++)
        if(isalnum(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || (new_id[i] == '.' && temp[temp.size()-1] != '.'))
            temp += new_id[i];
    new_id = temp;
    temp = "";

    //4
    if(new_id[0] == '.') new_id.erase(0, 1);
    if(new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

    //5
    if(new_id == "") new_id += 'a';

    //6
    if(new_id.size() > 15) new_id = new_id.substr(0, 15);
    if(new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

    //7
    if(new_id.size() < 3)
        while(new_id.size() < 3)
            new_id += new_id[new_id.size() - 1];

    return new_id;
}

// https://programmers.co.kr/learn/courses/30/lessons/72410

/*
����
���ڿ� ó���� ���� ����
1~7 �ܰ踦 ������� ó��
1. ��� �빮�ڸ� �ҹ��ڷ� ����
2. a~z, 0~9, -, _, . �� ������ ������ ���� ����
3. .�� ������ �پ������� �Ѱ��� ����
4. .�� ó���̳� ���� ������ ����
5. �� ���ڿ��� �Ǹ� a ����
6. 16���� �̻��̸� 15���� ������ ���ڴ� ����, �̶� .�� �������̸� . ����
7. ���ڿ��� ���̰� 2�� ���ϸ� ���̰� 3�� �ɶ����� ������ ���� �ݺ�
*/