#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_a = 0;
    int max_b = 0;
    for(vector<int> size : sizes)
    {
        int a = (size[0] <= size[1]) ? size[0] : size[1];
        int b = (size[0] > size[1]) ? size[0] : size[1];
        if(max_a < a) max_a = a;
        if(max_b < b) max_b = b;
    }

    return max_a * max_b;
}

// https://programmers.co.kr/learn/courses/30/lessons/86491

/*
명함을 돌려서 지갑에 넣을 수 있음
따라서 명함을 정렬을해 가장 큰 길이를 찾거나
가로 세로 중 긴 것과 짧은 것을 선택해서 해도 됨 -> 이걸로 코딩
*/