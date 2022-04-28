#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#include <iostream>
using namespace std;

struct Index
{
    int left;
    int right;
    int size;
};

bool cmp(Index a, Index b)
{
    if(a.size == b.size)
        return a.left < b.left;
    else
        return a.size < b.size;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<Index> answer_index;
    int gems_size = gems.size();
    int left = 0;
    int right = 0;

    //��ü ������ ������ ����
    unordered_set<string> gems_type;
    for(int i = 0 ; i < gems_size ; i++)
        gems_type.insert(gems[i]);
    int type_size = gems_type.size();
    if(type_size == 1) return {1, 1};

    //���� ���� �ִ� ������
    unordered_map<string, vector<int>> gems_map;
    //���� ���� �ִ� ������ ����
    unordered_set<string> gems_set;
    //ù��° ����
    gems_map[gems[0]].push_back(0);
    gems_set.insert(gems[0]);
    while(right < gems_size)
    {
        string lstr = gems[left];
        if(gems_map[lstr].size() > 1)
        {
            while(gems_map[lstr].size() > 1)
            {
                gems_map[lstr].erase(gems_map[lstr].begin());
                left++;
                lstr = gems[left];
            }
        }
        else if(gems_set.size() <= type_size)
        {
            right++;
            if(right == gems_size) break;
            string temp = gems[right];
            gems_set.insert(temp);
            gems_map[temp].push_back(right);
        }

        if(gems_set.size() == type_size)
        {
            Index temp;
            temp.left = left;
            temp.right = right;
            temp.size = right - left + 1;
            answer_index.push_back(temp);
        }
    }

    sort(answer_index.begin(), answer_index.end(), cmp);
    answer.push_back(answer_index[0].left + 1);
    answer.push_back(answer_index[0].right + 1);

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/67258

/*
�� ����Ʈ �˰����� ���
�ϳ��� �迭�� 2���� �����͸� ���
left <= right �� �����ؾ� ��

gems�� set�� �ְų� unique�� value�� ������ ��ü ���������� ���� �˾Ƴ�
(arr�� ���� index�� 1���� ������)

right�� +1�ϸ鼭 �ؾ��� �ൿ
    left�� �ִ� ������ �����ȿ� �ߺ��ƴ��� Ȯ��
        �ߺ��Ǿ��ٸ� left+1
    left~right�� �ִ� ���� �� == ��ü ���� ��
        �����ϴٸ� (left, right, right-left) ����

left�� +1�ϸ鼭 �ؾ��� �ൿ
    +1�Ǿ��⿡ �ٽ� left�� ������ �����ȿ� �ߺ��ƴ��� Ȯ��
        �ߺ��Ǿ��ٸ� left+1
    

*/