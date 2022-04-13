#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int select = nums.size()/2;
    unordered_set<int> unique_monster;
    
    for(int num : nums)
        unique_monster.insert(num);

    if(select <= unique_monster.size())
        answer = select;
    else
        answer = unique_monster.size();

    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/1845

/*
����
���ϸ��� ��/2 ��ŭ ����
�ִ��� �ߺ����� ���� ���ϸ��� �̾ƾ� ��

n/2�� ����
���ϸ��� set�� �����ؼ� �ߺ����� ����
ũ�⸦ ��
if(n/2 <= set.size()) // ����ũ�� ���ϸ��� ���� ������ �� �ִ� �纸�� ����
    answer = n/2 // �� �����ص� ���� ����ũ��
if(n/2 > set.size()) // ������ �� �ִ� �纸�� ����ũ�� ���ϸ��� ���� ����
    answer = set.size() // ����ũ ������ ���� ��

----------������ �ڵ�� ���氡��--------------------
int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}
*/
