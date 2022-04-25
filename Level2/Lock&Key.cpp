#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int turn = 0;
    bool flag = true;
    int keysize = key.size();
    int locksize = lock.size();

    while(turn < 4)
    {
        //lock의 기준점 찾기
        int locki = 0;
        int lockj = 0;
        flag = true;
        for(int i = 0; i < locksize; i++)
        {
            for(int j = 0 ; j < locksize ; j++)
            {
                if(lock[i][j] == 0)
                {
                    locki = i;
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        flag = true;
        for(int j = 0; j < locksize; j++)
        {
            for(int i = 0 ; i < locksize ; i++)
            {
                if(lock[i][j] == 0)
                {
                    lockj = j;
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }

        //key, lock의 홈과 돌기가 알맞는지 확인
        for(int keyi = 0 ; keyi < keysize ; keyi++)
        {
            for(int keyj = 0 ; keyj < keysize ; keyj++)
            {
                int ki = keyi;
                int li = locki;
                flag = true;
                while(flag && li < locksize)
                {
                    int kj = keyj;
                    for(int lj = lockj ; lj < locksize ; lj++)
                    {
                        int num = 0;
                        if(ki < keysize && kj < keysize)
                            num = key[ki][kj] + lock[li][lj];
                        else
                            num = lock[li][lj];
                        
                        if(num != 1)
                        {
                            flag = false;
                            break;
                        }
                        kj++;
                    }
                    ki++;
                    li++;
                }
                if(flag) return true;
            }
        }
       

        //시계 회전
        vector<vector<int>> temp = key;
        int size = keysize - 1;
        for(int i = 0 ; i < keysize ; i++)
        {
            for(int j = 0 ; j < keysize ; j++)
            {
                temp[i][j] = key[size - j][i];
            }
        }        
        key = temp;
        turn++;
    }
    
    return false;
}

//https://programmers.co.kr/learn/courses/30/lessons/60059

/*
열쇠는 회전과 이동이 가능함
열쇠, 자물쇠는 (3~20)NxN 의 정사각형 2차원 배열
0은 홈 1은 돌기
열쇠의 1과 자물쇠의 홈 부분이 일치해야 함
열쇠의 돌기와 자물쇠의 돌기가 만나면 안됨
모든 자물쇠의 홈을 채워야 함
-> 전부 더했을때 NxN의 모든 원소가 1이면 ok

while(열쇠 회전 횟수 < 4)
    기준점을 찾음
    자물쇠에 열쇠에 값을 더하기 시작
        if(값 != 1) break;
        if(모든 값이 1) return true;

세로 : i
가로 : j
기준점 찾기-------------------------------
열쇠
0 a 1
0 0 0
0 1 0
-> a가 기준점이 될 것임
i를 0~N i++
처음 만나는 1일 때, i를 저장
j를 0~N j++
처음 만나는 1일 때, j를 저장
i, j가 기준점

자물쇠
1 a 0
1 1 1
1 0 1
-> a가 기준점
i를 0~N i++
처음 만나는 0일 때, i를 저장
j를 0~N j++
처음 만나는 0일 때, j를 저장
i, j가 기준점
--------오류 발생----------
키의 기준점을 좌측 상단으로 고정해버려서 일어나는 문제


시계회전--------------------------------------
4x4
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33
00->03
01->13
02->23
03->33
10->02
11->12
12->22
13->32
...
ab -> b(N-a)가 됨
반시계 회전에 대해서는 시계회전의 3번과 동일, 확인해야 할 회전 수는 각 이동에 대해 3번씩 일어나면 됨
    0-90-180-270//-360(0)

*/