#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<vector<string>> relations) {
    int answer = 0;
    int column = relations[0].size();
    int row = relations.size();
    vector<bool> isUsed(relations[0].size(), false);
    vector<string> combi_vec;
    
    //i�� false�� ��, �������� �ʴ� attribute�� ��
    for(int i = column - 1 ; i >= 0 ; i--)
    {
        vector<bool> combi(i, false);
        combi.insert(combi.end(), column - i, true);
        do
        {
            unordered_set<string> s;

            for(vector<string> relation : relations)
            {
                string str = "";
                for(int i = 0 ; i < column ; i++)
                {
                    if(combi[i]) str += relation[i];
                }
                s.insert(str);
            }
            if(s.size() == row)
            {
                string temp = "";
                for(int i = 0 ; i < column ; i++)
                {
                    if(combi[i])
                    {
                        isUsed[i] = true;
                        temp += to_string(i);
                    }
                }
                combi_vec.push_back(temp);
            }
        }while(next_permutation(combi.begin(), combi.end()));
    }
    
    isUsed.clear();
    isUsed.insert(isUsed.end(), combi_vec.size(), false);
    for(int i = 0 ; i < combi_vec.size() ; i++)
    {
        if(isUsed[i]) continue;
        isUsed[i] = true;
        answer++;

        string temp = combi_vec[i];
        cout << temp << "\n";
        for(int j = i+1 ; j < combi_vec.size() ; j++)
        {
            int k = 0;
            for( ; k < temp.length() ; k++)
            {
                if(combi_vec[j].find(temp[k]) == string::npos)
                {
                    break;
                }
            }
            if(k == temp.length())
            {
                isUsed[j] = true;
            }
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42890

/*
���ϼ� : ��� Ʃ�ÿ� ���� �����ϰ� �ĺ��Ǿ�� ��, �� �ߺ��Ǵ� ���� ������ �ȵ�
�ּҼ� : ��� �ϳ��� �Ӽ��̶� �����ϴ� ��쿡�� ���ϼ��� ����ȴٸ� ���� ����

���ϼ��� �ش��ϱ� ���� �� ��ҵ��� set�� ����, set�� ũ�Ⱑ ��ҵ��� ������ �����ϸ� ������
    (set�� �ߺ��� ������� �ʱ� ������ �ߺ��� ���, ������ �������� �ʰ� ��)

�ּҼ��� �����ϱ� ���� ���ϼ� �ܰ迡�� ������ ������ �����
���� ��Һ��� ���, ���� ������ ��ҿ� �ߺ��Ǿ����� ��Ұ� �ִٸ� ����
ex) 0, 01, 02, 12, 123
-> 0�� ������ ���� 01, 02, 12, 123�� ����
   01, 02�� 0�� �ߺ��Ǿ���
   01, 02����
-> 12�� ������ ���� 123�� ����
   123���� 12�� �ߺ��Ǿ���
   123����
�� : 2��
*/
