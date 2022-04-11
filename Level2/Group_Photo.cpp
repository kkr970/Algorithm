#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<char> names;

int GetIndex(char c)
{
    for(int i = 0 ; i < 8 ; i++)
        if(names[i] == c)
            return i;
    return -1;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    names = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    do{
        bool check = false;
        for(string condition : data)
        {
            if(check) break;

            int me = GetIndex(condition[0]);
            int you = GetIndex(condition[2]);
            char operation = condition[3];
            int distance = condition[4] - '0';

            if(operation == '<' && abs(me - you) - 1 >= distance)
                check = true;
            else if(operation == '>' && abs(me - you) - 1 <= distance)
                check = true;
            else if(operation == '=' && abs(me - you) - 1 != distance)
                check = true;
        }
        if(!check) answer++;
	}while(next_permutation(names.begin(), names.end()));

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/1835

/*
����
�ɹ� : {A, C, F, J, M, N, R, T} // ������������ ���� �Ǿ� ����
next_permutation �� ����ؼ� ��� ����� ���� Ȯ���� �� ����

��� ��츶�� data�� �о� ������ �����ϴ��� Ȯ��
    ��� �����ϸ� answer++

data
0 = ��
1 = ~
2 = ���
3 = <, >, =
4 = �Ÿ�(��, ��� ���̿� �ִ� ģ���� ��)
    ��, ��� ������ �Ÿ��� abs(��.index - ���.index - 1)
*/
