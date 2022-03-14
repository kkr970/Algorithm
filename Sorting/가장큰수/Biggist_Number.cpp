#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(int i : numbers)
        temp.push_back(to_string(i));
    
    sort(temp.begin(), temp.end(), cmp);

    if(temp.at(0) == "0")
        return "0";
    for(string str : temp)
        answer += str;
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42746?language=cpp

/*
�����ؾ� ���� sort �Լ��� ���ؼ�
sort(i, j)
���� ����i ~ ����j���� ������������ ��������
i < j�� ��, ���Լ��� ���̶� swap�� �Ͼ�� ����

sort(i, j, func)
func�� �� �Լ��� ���µ�, �ڵ����� i, j�� ù��°, �ι�° �Ű������� �Էµ�
func�� ���̸� swap�� �Ͼ�� ����
���� cmp �Լ����� a + b > b + a�ε�
a�� 1,  b�� 2  ������ �ٲ��� ��
12 > 21 �� ���������� swap�� �Ͼ
�׷��� i, j�� ������ �ٲ�� ������ ���ڰ� ū b�� ������ ���� ��
*/