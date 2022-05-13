#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> temp(n, vector<int>(n));
    
    int x = -1; // 세로
    int y = 0; // 가로
    int num = 0;
    while(n > 0)
    {
        for(int i = 0 ; i < n ; i++)
        {
            temp[++x][y] = ++num;
        }
        for(int i = 0 ; i < n-1 ; i++)
        {
            temp[x][++y] = ++num;
        }
        for(int i = 0 ; i < n-2 ; i++)
        {
            temp[--x][--y] = ++num;
        }

        n -= 3;
    }

    for(int i = 1 ; i <= temp.size() ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            answer.push_back(temp[i-1][j]);
        }
    }

    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/68645

/*
높이가 주어짐,
i) 높이 = 4
index
    0
   1 2 
  3 4 5
 6 7 8 9
value
   1
  2 9
 3 10 8
4  5 6 7
*/