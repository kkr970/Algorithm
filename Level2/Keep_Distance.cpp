#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

#include <iostream>

using namespace std;

int findP = 0; // 자기자신P와 가까운P, 2가 되면 bfs 종료
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
        // i:좌우  j:상하
        for(int i = 0 ; i < 5 && isKeep ; i++)
        {
            for(int j = 0 ; j < 5 && isKeep ; j++)
            {
                if(place[i][j] == 'P')
                {
                    findP = 0;
                    bfs(place, i, j);
                    //찾은 P가 자기 자신일 뿐일 때
                    if(findP == 1) continue;
                    //찾은 두번째 P의 거리를 확인
                    if(findP == 2)
                    {
                        //거리가 2 이하, 다음 place 진행
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
거리두기를 지키면 1, 아니면 0을 return

-P는 사람
-O은 빈 테이블
-X는 파티션

강의실은 5x5 고정
사람 사이에 파티션이 있으면 지킴
사람 사이의 거리가 2 이하면 안됨 ( |r1 - r2| + |c1 - c2| )
빈 테이블은 빈 공간으로 생각

BFS를 이용하면 될 듯
ex)
P O O O P
O X X O X
O P X P X
O O X O X
P O X X P

-X가 아닌 P, O에 대해서 길을 찾음

배열을 모두 확인하면 종료
0,0부터 !isVisited && != 'X' 인 것을 검색해 나감
검색을 시작한 P에서 가장 가까운 P를 찾음
    가장 가까운 P의 멘헤튼 거리가 2 이하인 경우
        1 return 
    가까운 P를 찾음
        isVisited 초기화
        탐색 종료

*/