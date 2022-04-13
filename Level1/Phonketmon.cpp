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
생각
폰켓몬의 수/2 만큼 뽑음
최대한 중복되지 않은 폰켓몬을 뽑아야 함

n/2를 저장
폰켓몬을 set에 저장해서 중복값을 없앰
크기를 비교
if(n/2 <= set.size()) // 유니크한 폰켓몬의 수가 선택할 수 있는 양보다 많음
    answer = n/2 // 다 선택해도 전부 유니크함
if(n/2 > set.size()) // 선택할 수 있는 양보다 유니크한 폰켓몬의 수가 적음
    answer = set.size() // 유니크 종류의 수가 답

----------간단한 코드로 변경가능--------------------
int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}
*/
