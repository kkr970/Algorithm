#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int num)
{
    if(num < 2) return false;
    int a = (int)sqrt(num);
    for(int i = 2; i <= a ; i++)
        if(num % i == 0)
            return false;
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for(int i = 0 ; i < nums.size()-2 ; i++)
    {
        for(int j = i+1 ; j < nums.size()-1 ; j++)
        {
            for(int k = j+1 ; k < nums.size() ; k++)
            {
                if(isPrime(nums[i] + nums[j] + nums[k]))
                    answer++;
            }
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12977

/*
����
�迭�� 3�� �̻� 50�� ����
3���� �����ؼ� �Ҽ��� ����� ���� ����

*/