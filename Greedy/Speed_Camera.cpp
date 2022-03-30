#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    int camera_pos = -40000;

    sort(routes.begin(), routes.end());

    for (vector<int> route : routes)
    {
        if (camera_pos < route[0])
        {
            answer++;
            camera_pos = route[1];
        }
        if (camera_pos >= route[1])
            camera_pos = route[1];
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42884

/*
생각
차량의 진입, 진출 지점에도 카메라가 설치 되어도 됨
진입을 기준으로 카메라가 설치될 경우보다 진출을 기준으로 설치되는 경우가 효율적임

1번의 진출시간보다 진입 시간이 빠른 차들은 무시
    1번의 진출시간보다 진입 시간이 느린 차들은 카메라에 단속되지 않기 때문에
    느린차를 만나면 2번이라고 생각, answer++
    카메라의 위치보다  먼저 나가는 차량이 있다면, 카메라의 위치를 변경
2번의 진출시간보다 진입 시간이 빠른 차들은 무시
    반복...
차량을 전부 확인하면 끝

return answer;
*/
