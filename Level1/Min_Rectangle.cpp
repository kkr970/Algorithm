#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_a = 0;
    int max_b = 0;
    for(vector<int> size : sizes)
    {
        int a = (size[0] <= size[1]) ? size[0] : size[1];
        int b = (size[0] > size[1]) ? size[0] : size[1];
        if(max_a < a) max_a = a;
        if(max_b < b) max_b = b;
    }

    return max_a * max_b;
}

// https://programmers.co.kr/learn/courses/30/lessons/86491

/*
������ ������ ������ ���� �� ����
���� ������ �������� ���� ū ���̸� ã�ų�
���� ���� �� �� �Ͱ� ª�� ���� �����ؼ� �ص� �� -> �̰ɷ� �ڵ�
*/