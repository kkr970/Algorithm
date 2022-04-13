#include <string>
#include <vector>

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = a;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int **mat = new int*[rows];
    for(int i = 0 ; i < rows ; i++)
        mat[i] = new int[columns];

    int num = 1;
    for(int i = 0 ; i < rows ; i++)
        for(int j = 0 ; j < columns ; j++)
            mat[i][j] = num++;

    for(vector<int> query : queries)
    {
        //x row, y columns, mat[row][columns]
        //x가 세로 y가 가로
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;

        int min_num = mat[x1][y1];
        for(int i = x1 ; i < x2 ; i++)
        {
            if(min_num > mat[i+1][y1]) min_num = mat[i+1][y1];
            swap(mat[i][y1], mat[i+1][y1]);
        }
        for(int i = y1 ; i < y2 ; i++)
        {
            if(min_num > mat[x2][i+1]) min_num = mat[x2][i+1];
            swap(mat[x2][i], mat[x2][i+1]);
        }
        for(int i = x2 ; i > x1 ; i--)
        {
            if(min_num > mat[i-1][y2]) min_num = mat[i-1][y2];
            swap(mat[i][y2], mat[i-1][y2]);
        }
        for(int i = y2 ; i > y1 + 1 ; i--)
        {
            if(min_num > mat[x1][i-1]) min_num = mat[x1][i-1];
            swap(mat[x1][i], mat[x1][i-1]);
        }    
        
        answer.push_back(min_num);
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/77485

/*
생각
1)
배열을 실제로 값을 넣고
값의 위치를 변경하고
작은 값을 찾아서 return하기

*/