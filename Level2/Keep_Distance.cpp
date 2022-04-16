#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

#include <iostream>

using namespace std;

int findP = 0; // �ڱ��ڽ�P�� �����P, 2�� �Ǹ� bfs ����
int Pi, Pj;

void bfs(vector<string> place, int i, int j)
{
    queue<pair<int, int>> q;

    bool isVisited[5][5] = {false};
    memset(isVisited, false, sizeof(isVisited));

    q.push(make_pair(i, j));
    while(!q.empty() && findP < 2)
    {
        pair<int, int> cur = q.front();
        int curi = cur.first;
        int curj = cur.second;
        q.pop();
        
        isVisited[curi][curj] = true;
        if(place[curi][curj] == 'P')
        {
            Pi = curi;
            Pj = curj;
            findP++;
        }
        if(curi != 4 && !isVisited[curi+1][curj] && place[curi+1][curj] != 'X')
            q.push(make_pair(curi+1, curj));
        if(curi != 0 && !isVisited[curi-1][curj] && place[curi-1][curj] != 'X')
            q.push(make_pair(curi-1, curj));
        if(curj != 4 && !isVisited[curi][curj+1] && place[curi][curj+1] != 'X')
            q.push(make_pair(curi, curj+1));
        if(curj != 0 && !isVisited[curi][curj-1] && place[curi][curj-1] != 'X')
            q.push(make_pair(curi, curj-1));
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool isKeep = true;
    Pi = 0;
    Pj = 0;

    for(vector<string> place : places)
    {
        isKeep = true;
        // i:�¿�  j:����
        for(int i = 0 ; i < 5 && isKeep ; i++)
        {
            for(int j = 0 ; j < 5 && isKeep ; j++)
            {
                if(place[i][j] == 'P')
                {
                    findP = 0;
                    bfs(place, i, j);
                    //ã�� P�� �ڱ� �ڽ��� ���� ��
                    if(findP == 1) continue;
                    //ã�� �ι�° P�� �Ÿ��� Ȯ��
                    if(findP == 2)
                    {
                        //�Ÿ��� 2 ����, ���� place ����
                        if(abs(i - Pi) + abs(j - Pj) <= 2)
                        {
                            answer.push_back(0);
                            isKeep = false;
                        }
                    }
                }
            }
        }
        if(isKeep) answer.push_back(1);
    }

    return answer;
}

int main(){
    vector<vector<string>> places;
    vector<string> place;

    place.push_back("POOOP");
    place.push_back("OXXOX");
    place.push_back("OPXPX");
    place.push_back("OOXOX");
    place.push_back("POXXP");

    places.push_back(place);

    for(int a : solution(places))
        cout << a << "\n";

    return 0;
}
// https://programmers.co.kr/learn/courses/30/lessons/81302

/*
�Ÿ��α⸦ ��Ű�� 1, �ƴϸ� 0�� return

-P�� ���
-O�� �� ���̺�
-X�� ��Ƽ��

���ǽ��� 5x5 ����
��� ���̿� ��Ƽ���� ������ ��Ŵ
��� ������ �Ÿ��� 2 ���ϸ� �ȵ� ( |r1 - r2| + |c1 - c2| )
�� ���̺��� �� �������� ����

BFS�� �̿��ϸ� �� ��
ex)
P O O O P
O X X O X
O P X P X
O O X O X
P O X X P

-X�� �ƴ� P, O�� ���ؼ� ���� ã��

�迭�� ��� Ȯ���ϸ� ����
0,0���� !isVisited && != 'X' �� ���� �˻��� ����
�˻��� ������ P���� ���� ����� P�� ã��
    ���� ����� P�� ����ư �Ÿ��� 2 ������ ���
        1 return 
    ����� P�� ã��
        isVisited �ʱ�ȭ
        Ž�� ����

*/