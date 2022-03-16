#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int num){
    if(num <= 1)
        return false;

    for(int i = 2; i <= sqrt(num); i++)
        if((num % i) == 0)
            return false;

    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    vector<int> numbers_vec;
    do{
		for(int i = 0 ; i < numbers.size() ; i++){
			numbers_vec.push_back( stoi(numbers.substr(0, i+1)) );
		}
	}while(next_permutation(numbers.begin(), numbers.end()));
    
    sort(numbers_vec.begin(), numbers_vec.end());
    numbers_vec.erase(unique(numbers_vec.begin(),numbers_vec.end()),numbers_vec.end());
    
    for(int num : numbers_vec)
    {
        if(isPrime(num))
            answer++;
    }
    
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42839
/*
�����ؾ� �� ��
next_permutation�Լ�
������ �ٲ��ָ�, ������ �������� �ٲ���, ���������� ����, �迭�� �ʿ���

-algorithm ���̺귯���� ���� �Լ����� �˾ƺ� �ʿ䰡 ���� �� ���ƺ���
ó�� ����غ��� �Լ��� ����
-https://modoocode.com/256

*/