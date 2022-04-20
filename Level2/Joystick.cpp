#include <string>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;

    int right_left = name.length() - 1;
    for(int i = 0 ; i < name.length() ; i++)
    {
        //i == 0 일때, 전부 왼쪽으로 이동하는 것을 계산하게 됨
        if(name[i] == 'A' && i != 0) continue;

        char c = name[i];
        int num = min(c - 'A', 'Z' - c + 1);
        answer += num;

        int next = i+1;
        while(next < name.length() && name[next] == 'A') next++;

        right_left = min(right_left, i*2 + (int)(name.length()-next));
        right_left = min(right_left, (int)(name.length()-next)*2 + i);
    }    
    answer += right_left;
    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/42860

/*
처음의 상태는 A만으로 이루어져 있음
커서를 좌우로 이동, 커서를 알파벳을 1칸씩 변경 당 1번의 움직임이 늘어남

그리디로 분류되어 있으나, 이 문제는 그리디로 해결하면 풀 수 없는 문제
ex) BBBBAAAAABA의 경우
DLLDRRRDRDRD -> 12번으로 해결이 가능함
그러나 그리디로 해결하면 좌, 우를 비교하면 오른쪽으로 가는 것이 그리디함
DRDRDRDLLLLLD -> 13번으로 해결됨

상하) string에 대해 각 index당 위, 아래를 움직여야 하는 횟수를 저장항, 전부 더함

좌우) value가 0이 아닌 index에 대해서 좌, 우로 움직이는 최소한의 수를 구해야함

i, i+1에 해당하는 값을 가지고
0 -> i -> 0 -> i+1 // 0->i==i번, i->0==i번, 0->i+1==길이-(i+1)번 ,총합 = i*2 + 길이-(i+1)
0 -> i+1 -> 0 -> i // 총합 = (길이-(i+1))*2 + i
중 작은수를 선택, 저장되어있는 이동횟수 중 작은 횟수를 선택함

return 좌우 + 상하
*/

"BBABAAAABBBAAAABABB" 26
"BBAAAAAABBBAAAAAABB" 20
"BBBAAAAAAAB" 8
"ABAAAAAAAAABB" 7
"BBAABB" 8
"BBBAAAAABAAAAAAAAAAA" 12
"BAAAAAAAAAABAAAAAABB" 13
"AAABBAB" 7