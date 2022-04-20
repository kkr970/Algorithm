#include <string>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;

    int right_left = name.length() - 1;
    for(int i = 0 ; i < name.length() ; i++)
    {
        //i == 0 �϶�, ���� �������� �̵��ϴ� ���� ����ϰ� ��
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
ó���� ���´� A������ �̷���� ����
Ŀ���� �¿�� �̵�, Ŀ���� ���ĺ��� 1ĭ�� ���� �� 1���� �������� �þ

�׸���� �з��Ǿ� ������, �� ������ �׸���� �ذ��ϸ� Ǯ �� ���� ����
ex) BBBBAAAAABA�� ���
DLLDRRRDRDRD -> 12������ �ذ��� ������
�׷��� �׸���� �ذ��ϸ� ��, �츦 ���ϸ� ���������� ���� ���� �׸�����
DRDRDRDLLLLLD -> 13������ �ذ��

����) string�� ���� �� index�� ��, �Ʒ��� �������� �ϴ� Ƚ���� ������, ���� ����

�¿�) value�� 0�� �ƴ� index�� ���ؼ� ��, ��� �����̴� �ּ����� ���� ���ؾ���

i, i+1�� �ش��ϴ� ���� ������
0 -> i -> 0 -> i+1 // 0->i==i��, i->0==i��, 0->i+1==����-(i+1)�� ,���� = i*2 + ����-(i+1)
0 -> i+1 -> 0 -> i // ���� = (����-(i+1))*2 + i
�� �������� ����, ����Ǿ��ִ� �̵�Ƚ�� �� ���� Ƚ���� ������

return �¿� + ����
*/

"BBABAAAABBBAAAABABB" 26
"BBAAAAAABBBAAAAAABB" 20
"BBBAAAAAAAB" 8
"ABAAAAAAAAABB" 7
"BBAABB" 8
"BBBAAAAABAAAAAAAAAAA" 12
"BAAAAAAAAAABAAAAAABB" 13
"AAABBAB" 7