#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    vector<string> str_vec;
    
    //문자열을 자를 단위
    for(int i = s.length() / 2 ; i > 0 ; i--)
    {
        string temp = "";
        for(int j = 0 ; j < s.length() ; j++)
        {
            temp += s[j];
            if(j % i == i - 1)
            {
                str_vec.push_back(temp);
                temp = "";
            }
            else if(j == s.length() - 1 && temp != "")
            {
                str_vec.push_back(temp);
            }
        }
        
        temp = "";
        string answer_string = "";
        int num = 1;
        for(string str : str_vec)
        {
            if(temp != str)
            {
                temp = str;
                if(num > 1)
                {
                    answer_string += to_string(num);
                    num = 1;
                }
                answer_string += str;
            }
            else //(temp == str)
                num++;
        }
        if(num > 1)
        {
            answer_string += to_string(num);
            num = 1;
        }
        if(answer > answer_string.length())
            answer = answer_string.length();

        str_vec.clear();
    }
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/60057

/*
생각
문자열 길이 / 2 -> 0까지 내리면서 확인하는게 맞지 않을까

1234 5678 9
벡터에 문자열을 잘라서 넣기
나머지 뒤에 단위보다 짧은 길이의 문자열도 따로 추가

num=1
벡터 하나씩 꺼내면서
{
    처음보는 str이면 if(num>1){answer+= num, num=1}, answer+= str
    이전 것과 같은 str이면 num++
}

*/