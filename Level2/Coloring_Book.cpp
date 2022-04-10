#include <vector>
#include <iostream>
using namespace std;

int number_of_area;
int max_size_of_one_area;
int size_of_one_area;
int max_i;
int max_j;

void dfs(vector<vector<int>> &picture, int i, int j)
{
    if(picture[i][j] == 0) return;
    int cur_color = picture[i][j];
    picture[i][j] = 0;
    size_of_one_area++;
    
    //up
    if(i != 0 && cur_color == picture[i-1][j])
        dfs(picture, i-1, j);
    //left
    if(j != 0 && cur_color == picture[i][j-1])
        dfs(picture, i, j-1);
    //down
    if(i != max_i && cur_color == picture[i+1][j])
        dfs(picture, i+1, j);
    //right
    if(j != max_j && cur_color == picture[i][j+1])
        dfs(picture, i, j+1);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    number_of_area = 0;
    max_size_of_one_area = 0;
    size_of_one_area = 0;
    max_i = m - 1;
    max_j = n - 1;
    
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(picture[i][j] != 0)
            {
                //cout << "영역의 색 : " << picture[i][j] << "\n";
                dfs(picture, i, j);
                if(max_size_of_one_area < size_of_one_area)
                    max_size_of_one_area = size_of_one_area;
                //cout << "영역의 넓이 : " << size_of_one_area << "\n\n";
                size_of_one_area = 0;
                number_of_area++;
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/1829

/*
생각
상하좌우에 같은 변수가 있으면 같은 영역
[1, 1, 1, 0]
[1, 1, 1, 0]
[0, 0, 0, 1]
[0, 0, 0, 1]
[0, 0, 0, 1]
[0, 0, 0, 1]

[1, 1, 1, 1],
[1, 2, 2, 1],
[1, 0, 0, 1],
[0, 0, 1, 1],
[0, 0, 0, 3],
[0, 0, 0, 3]

dfs, bfs
picture[i][j] != 0 -> dfs 시작, 방문한 노드 -> picture[i][j] = 0
    if (answer[1] < 노드 수)
        answer[1] = 노드 수
    answer[0]++ //영역의 수
picture[i][j] == 0 -> 패스

return answer

*/
