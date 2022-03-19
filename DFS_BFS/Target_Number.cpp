#include <string>
#include <vector>

using namespace std;

int answer = 0;
int max_depth, t;

void dfs(vector<int>& v, int sum, int depth)
{
    if(depth == max_depth)
    {
        if(sum == t)
        {
            answer++;
            return;
        }
        else
            return;
    }
    dfs(v, sum + v[depth], depth + 1);
    dfs(v, sum - v[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    max_depth = numbers.size();
    t = target;

    dfs(numbers, 0, 0);

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/43165

/*
����
DFS�� ���
�ڽĳ��� ������ -, �������� +�� ����
���̿� ���� ���° index���� �Ǵ�
��� ������ �� ���� �� ���
leaf ����� ��(���̰� �ִ�) target number���� Ȯ��
target number�� ���, answer + 1


������� �� DFS, BFS ���� ���
DFS : Stack / ��� �Լ�
BFS : Queue
*/