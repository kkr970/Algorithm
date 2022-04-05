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
생각
문자열 처리에 관한 내용
1~7 단계를 순서대로 처리
1. 모든 대문자를 소문자로 변경
2. a~z, 0~9, -, _, . 을 제외한 나머지 문자 제거
3. .이 여러개 붙어있으면 한개로 변경
4. .가 처음이나 끝에 있으면 제거
5. 빈 문자열이 되면 a 삽입
6. 16글자 이상이면 15글자 이후의 문자는 제거, 이때 .이 마지막이면 . 제거
7. 문자열의 길이가 2자 이하면 길이가 3이 될때까지 마지막 문자 반복
*/