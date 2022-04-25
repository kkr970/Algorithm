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
        //lock�� ������ ã��
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

        //key, lock�� Ȩ�� ���Ⱑ �˸´��� Ȯ��
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
       

        //�ð� ȸ��
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
����� ȸ���� �̵��� ������
����, �ڹ���� (3~20)NxN �� ���簢�� 2���� �迭
0�� Ȩ 1�� ����
������ 1�� �ڹ����� Ȩ �κ��� ��ġ�ؾ� ��
������ ����� �ڹ����� ���Ⱑ ������ �ȵ�
��� �ڹ����� Ȩ�� ä���� ��
-> ���� �������� NxN�� ��� ���Ұ� 1�̸� ok

while(���� ȸ�� Ƚ�� < 4)
    �������� ã��
    �ڹ��迡 ���迡 ���� ���ϱ� ����
        if(�� != 1) break;
        if(��� ���� 1) return true;

���� : i
���� : j
������ ã��-------------------------------
����
0 a 1
0 0 0
0 1 0
-> a�� �������� �� ����
i�� 0~N i++
ó�� ������ 1�� ��, i�� ����
j�� 0~N j++
ó�� ������ 1�� ��, j�� ����
i, j�� ������

�ڹ���
1 a 0
1 1 1
1 0 1
-> a�� ������
i�� 0~N i++
ó�� ������ 0�� ��, i�� ����
j�� 0~N j++
ó�� ������ 0�� ��, j�� ����
i, j�� ������
--------���� �߻�----------
Ű�� �������� ���� ������� �����ع����� �Ͼ�� ����


�ð�ȸ��--------------------------------------
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
ab -> b(N-a)�� ��
�ݽð� ȸ���� ���ؼ��� �ð�ȸ���� 3���� ����, Ȯ���ؾ� �� ȸ�� ���� �� �̵��� ���� 3���� �Ͼ�� ��
    0-90-180-270//-360(0)

*/