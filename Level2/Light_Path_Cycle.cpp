#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int path_length = 0;
    int v = grid.size(); // 세로
    int h = grid[0].size(); // 가로

    //가장 안쪽의 데이터 : (나감)상우하좌
    vector<vector<vector<int>>> vec3(v, vector<vector<int>>(h, vector<int>(4, 0)));

    //i-세로, j-가로, k-데이터
    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < h ; j++)
        {
            // 방향은 나가는 것만 생각하였음
            for(int k = 0 ; k < 4 ; k++)
            {
                //한번도 사용하지 않은 방향
                if(vec3[i][j][k] == 0)
                {
                    // 루트 탐색 시작
                    int a = i;
                    int b = j;
                    int c = k;
                    while(vec3[a][b][c] != 1)
                    {
                        vec3[a][b][c] = 1; //1=path 사용
                        path_length++;
                        
                        switch (c)
                        {
                        //위로 나감
                        case 0:
                            a = ((a+v) - 1)%v;
                            break;
                        //오른쪽으로 나감
                        case 1:
                            b = ((b+h) - 1)%h;
                            break;
                        //아래로 나감
                        case 2:
                            a = (a+1)%v;
                            break;
                        //왼쪽으로 나감
                        case 3:
                            b = (b+1)%h;
                            break;
                        default:
                            break;
                        }
                        //노드에 따라 나갈 방향을 변경 / S는 변경이 없음
                        if(grid[a][b] == 'R') 
                            c = (c + 1) % 4;
                        else if(grid[a][b] == 'L')
                            c = ((c + 4) - 1) % 4;
                    }
                    answer.push_back(path_length);
                    path_length = 0;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/86052

/*
grid에 노드가 주어짐, 노드는 s, r l가 주어짐

입자당 들어올 수 있는 방향은 4가지, 상하좌우
입자당 나갈 수 있는 방향은 4가지, 상하좌우

입자 밖으로 향하면 반대편에 있는 입자로 들어감 -> 배열의 밖을 벗어날 수 없음
빛이 이동하다 이전에 지나갔던 경로를 똑같이 지나가게 되면 사이클
(sl, lr)
s l
l r
       나감    들어옴
배열 = 상하좌우 상하좌우
S = ㅁㅁㅁㅁ ㅁㅁㅁㅁ L = ㅁㅁㅁㅁ ㅁㅁㅁㅁ
L = ㅁㅁㅁㅁ ㅁㅁㅁㅁ R = ㅁㅁㅁㅁ ㅁㅁㅁㅁ


1. 상우하좌(나감)
1.1)입자가 좌우로 연결된 배열의 index
x1x2/x2x1

1.2)입자가 상하로 연결된 배열의 index
1x2x
2x1x

->노드로 들어오는 데이터가 필요한가? -> 노드는 나가는 것과 들어오는 것은 항상 쌍을 이룸
    ->필요 없다고 생각하여 제거

방향을 변경
1. S
    -아래에서 들어옴
        ->전 노드에서 위쪽으로 나갔으니 c == 0
        위쪽으로 나가야 하니 c == 0
    -왼쪽에서 들어옴
        ->전 노드에서 오른쪽으로 나갔으니 c == 1
        오른쪽으로 나가야 하니 c == 1
    -위에서 들어옴
        ->전 노드에서 아래쪽으로 나갔으니 c == 2
        아래쪽으로 나갸아 하니 c == 2
    -오른쪽에서 들어옴
        ->전 노드에서 왼쪽으로 나갔으니 c == 3
        왼쪽으로 나가야 하니 c == 3
    -> 이전의 c

2. R
    -아래에서 들어옴
        -> 전 노드에서 위쪽으로 나갔으니 c == 0
        오른쪽으로 나갸아 하니 c == 1
    -왼쪽에서 들어옴
        ->전 노드에서 오른쪽으로 나갔으니 c == 1
        아래쪽으로 나가야 하니 c == 2
    -위에서 들어옴
        ->전 노드에서 아래쪽으로 나갔으니 c == 2
        왼쪽으로 나갸아 하니 c == 3
    -오른쪽에서 들어옴
        ->전 노드에서 왼쪽으로 나갔으니 c == 3
        위쪽으로 나가야 하니 c == 0
    -> 이전의 (c + 1) % 4
    
3. L
    -아래에서 들어옴
        -> 전 노드에서 위쪽으로 나갔으니 c == 0
        왼쪽으로 나갸아 하니 c == 3
    -왼쪽에서 들어옴
        ->전 노드에서 오른쪽으로 나갔으니 c == 1
        위쪽으로 나가야 하니 c == 0
    -위에서 들어옴
        ->전 노드에서 아래쪽으로 나갔으니 c == 2
        오른쪽으로 나갸아 하니 c == 1
    -오른쪽에서 들어옴
        ->전 노드에서 왼쪽으로 나갔으니 c == 3
        아래쪽으로 나가야 하니 c == 2
    -> 이전의 ((c + 4) - 1) % 4
*/