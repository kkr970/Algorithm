#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    int camera_pos = -40000;

    sort(routes.begin(), routes.end());

    for (vector<int> route : routes)
    {
        if (camera_pos < route[0])
        {
            answer++;
            camera_pos = route[1];
        }
        if (camera_pos >= route[1])
            camera_pos = route[1];
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42884

/*
����
������ ����, ���� �������� ī�޶� ��ġ �Ǿ ��
������ �������� ī�޶� ��ġ�� ��캸�� ������ �������� ��ġ�Ǵ� ��찡 ȿ������

1���� ����ð����� ���� �ð��� ���� ������ ����
    1���� ����ð����� ���� �ð��� ���� ������ ī�޶� �ܼӵ��� �ʱ� ������
    �������� ������ 2���̶�� ����, answer++
    ī�޶��� ��ġ����  ���� ������ ������ �ִٸ�, ī�޶��� ��ġ�� ����
2���� ����ð����� ���� �ð��� ���� ������ ����
    �ݺ�...
������ ���� Ȯ���ϸ� ��

return answer;
*/
