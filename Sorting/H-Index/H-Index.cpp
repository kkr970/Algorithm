#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int index = 0;

    sort(citations.rbegin(), citations.rend());

    for(index = 0 ; index < citations.size(); index++)
        if(index + 1 >= citations.at(index))
            break;

    if(index == citations.size())
        return citations.size();
    else if(index == 0)
        return 0;
    else
    {
        for(int i = citations.at(index - 1) ; i > citations.at(index) ; i--)
        {
            if(index == i)
                return i;
        }
        return citations.at(index);
    }
    return -1;
}

// https://programmers.co.kr/learn/courses/30/lessons/42747

/* ����

���� �ο� Ƚ���� ����ִ� �迭�� ����
������������ �����ϰ� �ȴٸ� [index]���� ū ���� ���� �ڿ� ����
�Ǵ�, ������������ �����ϰ� �ȴٸ� [index]���� ū ���� ���� �տ� ����
index+1�� arr[index]�� �̻� �ο�� ���� ��
index + 1 >= h = arr[index]
ex) [1, 4, 4, 0, 5, 2] -> [5, 4, 4, 2, 1, 0]
-> index 3���� ����
4~2 ������ �� �� h�� �����ϴ� h�� ã��

[6, 5, 3, 1, 0]
-> index 2 ���� ����
5~3 ������ �� �� �����ϴ� ū ���� ã��

[0, 0, 0, 0, 0]
-> index�� 0���� ����

*/
