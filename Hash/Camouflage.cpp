#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> clothes_map;
    
    for(vector<string> temp : clothes)
        clothes_map[temp[1]]++;

    for(auto temp : clothes_map)
        answer *= (temp.second + 1);
    
    return answer - 1;
}


// https://programmers.co.kr/learn/courses/30/lessons/42578

/*
����
1) �ؽ����̺� ����, key�� ����1, ���Ǵ�2, ���Ǵ�3, �ѿ���4
    �ش��ϴ� ������ ��Ÿ���� value�� + 1
    ��� �ʵ��� ������ �̿�
    ���� �ʴ� ��츦 �����ϸ� ��
    ex)2��/ 1��/ 1��/ 1��
    �� : x, 1, 2 -> 3���� ���ɼ�
    ���� : x, 1 -> 2���� ���ɼ�
    ���� : x, 1 -> 2���� ���ɼ�
    �ѿ� : x, 1 -> 2���� ���ɼ�
    ��� ���� : 3 * 2 * 2 * 2 = 24��
    ���� ���� �ʴ� ���� ���� -> 24 - 1 = 23
    
2) �ؽ����̺��� ������� �ʾƵ� array�� {��, ����, ����, �ѿ�}
    ������ �����ؼ� ����ص� ���� ��
    �׷��� �ؽø� ����ؼ� Ǯ������ �ؽø� �����

������� ��
map�� insert�� ��, ���� key���� key�� �����Ϸ��� �� ��,
���� key���� ��� int�� 0���� �־���
*/