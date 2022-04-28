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

    //전체 보석의 종류를 구함
    unordered_set<string> gems_type;
    for(int i = 0 ; i < gems_size ; i++)
        gems_type.insert(gems[i]);
    int type_size = gems_type.size();
    if(type_size == 1) return {1, 1};

    //범위 내에 있는 보석들
    unordered_map<string, vector<int>> gems_map;
    //범위 내에 있는 보석의 종류
    unordered_set<string> gems_set;
    //첫번째 보석
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
투 포인트 알고리즘을 사용
하나의 배열에 2개의 포인터를 사용
left <= right 을 유지해야 함

gems를 set에 넣거나 unique한 value만 선택해 전체 보석종류의 수를 알아냄
(arr의 시작 index는 1부터 시작함)

right를 +1하면서 해야할 행동
    left에 있는 보석이 범위안에 중복됐는지 확인
        중복되었다면 left+1
    left~right에 있는 종류 수 == 전체 종류 수
        동일하다면 (left, right, right-left) 저장

left를 +1하면서 해야할 행동
    +1되었기에 다시 left의 보석이 범위안에 중복됐는지 확인
        중복되었다면 left+1
    

*/