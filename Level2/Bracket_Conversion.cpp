#include <string>
#include <vector>
#include <iostream>

using namespace std;

string conversion(string p)
{
    if(p == "") return "";
    int flag = 0;
    bool isCorrect = false;

    int i = 0;
    do
    {
        if(p[i] == '(')
        {
            if(i == 0) isCorrect = true;
            flag++;
        }
        else if(p[i] == ')')
        {
            if(i == 0) isCorrect = false;
            flag--;
        }
        i++;
    } while (flag != 0);
    string u = p.substr(0, i);
    string v = p.substr(i, p.length() - i);

    cout << "u : " << u << "\n";
    cout << "v : " << v << "\n";

    string temp = "";
    if(isCorrect)
    {
        temp += u;
        temp += conversion(v);
    }
    else
    {
        temp += '(';
        v = conversion(v);
        temp += v;
        temp += ')';
        u = u.substr(1, u.length()-2);
        for(int i = 0 ; i < u.length() ; i++)
        {
            if(u[i] == '(')
                u[i] = ')';
            else if(u[i] == ')')
                u[i] = '(';
        }
        temp += u;
    }
    cout << "temp : " << temp << "\n\n";
    return temp;
}

string solution(string p) {
    string answer = "";
    
    answer += conversion(p);

    return answer;
}

int main(){
    cout << solution("()))((()");

    return 0;
}

// https://programmers.co.kr/learn/courses/30/lessons/60058

/*
1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�. 
2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�.
    ��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�. 
3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�. 
  3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�. 
4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�. 
  4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�. 
  4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�. 
  4-3. ')'�� �ٽ� ���Դϴ�. 
  4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�. 
  4-5. ������ ���ڿ��� ��ȯ�մϴ�.

����-----------
�� ���ڿ��̸� ����
'(' �� ������ +1
')' �� ������ -1
���ڰ� + -> 0 -> �ùٸ� ��ȣ // u, isCorrect = true
���ڰ� - -> 0 -> �������� ��ȣ, �ùٸ�x // u, isCorrect = false
������ ���ڿ� -> v
---------------

1) isCorrect
    temp += u
    temp += ����(v)
2) !isCorrect
    temp�� += '('
    temp += v�� ���� ������ ��������� ����
    temp += v
    temp += ')'
    u�� ù, ������ ���ڸ� ����
    u�� ��ȣ�� ������ temp�ڿ� �̾� ����
return temp
    

*/
