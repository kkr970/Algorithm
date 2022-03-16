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
공부해야 할 점
next_permutation함수
순서를 바꿔주며, 다음의 순열으로 바꿔줌, 오름차순의 벡터, 배열이 필요함

-algorithm 라이브러리의 내부 함수들을 알아볼 필요가 있을 것 같아보임
처음 사용해보는 함수가 있음
-https://modoocode.com/256

*/