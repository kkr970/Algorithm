#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    vector<string> str_vec;
    
    //���ڿ��� �ڸ� ����
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
����
���ڿ� ���� / 2 -> 0���� �����鼭 Ȯ���ϴ°� ���� ������

1234 5678 9
���Ϳ� ���ڿ��� �߶� �ֱ�
������ �ڿ� �������� ª�� ������ ���ڿ��� ���� �߰�

num=1
���� �ϳ��� �����鼭
{
    ó������ str�̸� if(num>1){answer+= num, num=1}, answer+= str
    ���� �Ͱ� ���� str�̸� num++
}

*/