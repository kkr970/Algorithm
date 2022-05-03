#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compareID(string id, string ban)
{
    int id_length = id.length();
    int ban_length = ban.length();

    if(id_length != ban_length) return false;
    for(int i = 0 ; i < id_length ; i++)
    {
        if(ban[i] != '*' && id[i] != ban[i])
            return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    unordered_set<string> banned_list;

    sort(user_id.begin(), user_id.end());
    do
    {
        int i = 0;
        vector<string> temp;
        for( ; i < banned_id.size() ; i++)
        {
            if(compareID(user_id[i], banned_id[i]))
            {
                temp.push_back(user_id[i]);
                continue;
            }
            else break;
        }
        if(i == banned_id.size())
        {
            sort(temp.begin(), temp.end());
            string str = "";
            for(string s : temp)
                str += s;
            banned_list.insert(str);
        }
    } while (next_permutation(user_id.begin(), user_id.end()));
    
    return banned_list.size();
}

// https://programmers.co.kr/learn/courses/30/lessons/64064

/*
���� id�� �־���, �ҷ� id *�� ���Ե� ���̵� �־���
1234, 5678, 1678 // *678
-> �ҷ� ���̵�� 5678 1678�� �� �� ����
-> ��, �ҷ� ���̵� �ѹ� ���� ���̵�� �ٽ� ����� �� ����

1234, 5678, 1678 // *678, *678
-> �� ���, �ҷ� ���̵�� 5678, 1678�� ��

banned_id�� ���ÿ����� ������ �߿����� �ʱ� ������
banned_id�� �� �� �ִ� index�� ����, string�� ���� ��, string�� ������
���� string�� map�� ����
�̷��� �ϸ� map�� key������ banned_id�� �� �� �ִ� ���յ��� ����
��, key�� ������ return�ϸ� ��
*678 *678
1: 1234 5678 1678
2: 1234 1678 5678
3: 5678 1234 1678
4: 5678 1678 1234
5: 1678 1234 5678
6: 1678 5678 1234
->4, 6�� ���õ�
id�� ������ �̿��� �տ������� banned_id�� ��Ī�� ��Ȯ�ϰ� �Ͼ�� answer++
    ��, �Ȱ��� id�� ���õ� ��쿡�� answer++���� ����
    -> id�� ����, ������ string���� ��ȯ�Ͽ� set�� insert�ϸ� �ߺ� id ������ ���ܵ�


*/