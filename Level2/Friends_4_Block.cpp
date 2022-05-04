#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    set<pair<int, int>> delete_block; // <i, j>

    do
    {
        delete_block.clear();

        //i m : ����, ����    j n : ��, ����
        for(int i = 0 ; i < m-1 ; i++)
        {
            for(int j = 0 ; j < n-1 ; j++)
            {
                char cur = board[i][j];
                if(cur == '1') continue;
                if(cur == board[i+1][j] && cur == board[i][j+1] && cur == board[i+1][j+1])
                {
                    delete_block.insert(make_pair(i, j));
                    delete_block.insert(make_pair(i+1, j));
                    delete_block.insert(make_pair(i, j+1));
                    delete_block.insert(make_pair(i+1, j+1));
                }
            }
        }
        if(!delete_block.empty())
        {
            answer += delete_block.size();
            for(pair<int, int> temp : delete_block)
            {
                board[temp.first][temp.second] = '1';
            }
            for(int j = 0 ; j < n ; j++)
            {
                int height = 0;
                bool flag = false;
                for(int i = m-1 ; i >= 0 ; i--)
                {
                    if(board[i][j] == '1')
                    {
                        height++;
                        flag = true;
                    }
                    if(flag && board[i][j] != '1')
                    {
                        char c = board[i][j];
                        board[i][j] = board[i+height][j];
                        board[i+height][j] = c;
                    }
                }
            }
        }
    }while(!delete_block.empty());
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/17679

/*
�� ����� 2x2�� ���·� 4���� ������
�������� ��� ������ answer�� ����

����� Ȯ��, i+1, j+1, i+1 j+1 ��, ������, �Ʒ���, �밢�� 3���� Ȯ���Ͽ�
������ ����� ��� answer++, ���Ϳ� ��ġ�� ������
��� ����� ���캸�� ���Ͱ� ����ִٸ� �������� ����� ���⿡ return answer
���Ͱ� ���� �ʾҴٸ�, ���Ϳ� �ش��ϴ� ����� �����, ���� �ִ� ����� �Ʒ��� ���Ľ��Ѿ���
AABC
22BC
11BC
BCAA �� ���, ���ڰ� �������� ����̶�� �����ϸ�, AA�� �Ʒ��� 2ĭ�� �̵��ؾ� �� ����
-> �� ���� ������ ���̸� ����Ͽ� ���ں��� ���� �ִ� ��Ͽ� ���� i+(1�� ����)�� ��ü��
��, i=0�� �ִ� A���� 0+2 = 2, i=2�� �ִ� ���� ���� ��ϰ� ��ü�� ��
11BC
22BC
AABC
BCAA
�� �� ����
-> ���⼭ ���ڸ� �ٸ����� ���������, �̴� ��ġ�� �����ֱ� �����̰� ��� �Ȱ��� ���ڸ� ����ϸ� ��
    (����� A~Z�� �����)
-> �Ʒ��� ���� ������ �ϸ�, A~Z�� �ƴ� ���, ���̸� +1�� ����, A~Z�� ���� ���, ���̸�ŭ i�� ���ϸ�
    �߰��� ���� �׷��� ����� �������� �۵���

*/
