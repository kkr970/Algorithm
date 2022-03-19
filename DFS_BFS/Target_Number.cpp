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
생각
DFS를 사용
자식노드는 왼쪽은 -, 오른쪽은 +로 생각
깊이에 따라서 몇번째 index인지 판단
노드 진행할 때 마다 값 계산
leaf 노드일 때(깊이가 최대) target number인지 확인
target number일 경우, answer + 1


배워야할 점 DFS, BFS 제작 방법
DFS : Stack / 재귀 함수
BFS : Queue
*/