#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //vector<vector<string>> v(orders.size());

    for(int course_num : course)
    {
        vector<vector<string>> v(orders.size());
        // 2�� ���Ϳ� order�� �ش��ϴ� index�� course������ ���յ��� ����
        for(int i = 0 ; i < orders.size() ; i++)
        {
            string order = orders[i];
            if(order.length() < course_num) continue;

            vector<bool> combi(order.length() - course_num, false);
            combi.insert(combi.end(), course_num, true);
            do{
                string temp = "";
                for(int i = 0 ; i < order.length() ; i++)
                {
                    if(combi[i]) temp += order[i];
                }
                sort(temp.begin(), temp.end());
                v[i].push_back(temp);
            }while(next_permutation(combi.begin(), combi.end()));
        }
        // ���յ��� map�� ����, �ߺ��� ���� ����, �ִ� ����
        unordered_map<string, int> m;
        int max = 0;
        for(vector<string> v_temp : v)
        {
            for(string temp : v_temp)
            {
                m[temp]++;
                if(max < m[temp]) max = m[temp];
            }
        }
        // value�� max(max>=2)�� string�� answer�� ����
        if(max >= 2)
            for(pair<string, int> temp : m)
            {
                if(temp.second == max) answer.push_back(temp.first);
            }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/72411

/*
course�� �޴��� ������ ������
�Ŵ��� ������ ������ ����µ�
2���� ���͸� ����� orders�� �ش��ϴ� �ε��� ���Ϳ� ������ ����

���յ��� map<string, int>�� ����, �޴��̸�, �Ҹ� Ƚ���� ������
int�� �ִ밪�� ���� string�� answer�� ����

-- ����ó��
1. 2 �̻��� �մ��� �ֹ��ؾ� ��
    -> �Ҹ� Ƚ���� �ִ밪�� 2���� ������ pass
2. �޴��� ������ ���ĵǾ� ���� ���� ���
    -> ������ ��, string�� �����ؼ� ����
*/