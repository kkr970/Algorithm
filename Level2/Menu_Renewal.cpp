#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //vector<vector<string>> v(orders.size());

    for(int course_num : course)
    {
        vector<vector<string>> v(orders.size());
        // 2중 벡터에 order에 해당하는 index에 course길이의 조합들을 저장
        for(int i = 0 ; i < orders.size() ; i++)
        {
            string order = orders[i];
            if(order.length() < course_num) continue;

            vector<bool> combi(order.length() - course_num, false);
            combi.insert(combi.end(), course_num, true);
            do{
                string temp = "";
                for(int i = 0 ; i < order.length() ; i++)
                {
                    if(combi[i]) temp += order[i];
                }
                sort(temp.begin(), temp.end());
                v[i].push_back(temp);
            }while(next_permutation(combi.begin(), combi.end()));
        }
        // 조합들을 map에 저장, 중복된 수를 저장, 최댓값 저장
        unordered_map<string, int> m;
        int max = 0;
        for(vector<string> v_temp : v)
        {
            for(string temp : v_temp)
            {
                m[temp]++;
                if(max < m[temp]) max = m[temp];
            }
        }
        // value가 max(max>=2)인 string을 answer에 저장
        if(max >= 2)
            for(pair<string, int> temp : m)
            {
                if(temp.second == max) answer.push_back(temp.first);
            }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/72411

/*
course에 메뉴의 갯수가 정해짐
매뉴의 갯수의 조합을 만드는데
2차원 벡터를 만들어 orders에 해당하는 인덱스 벡터에 조합을 저장

조합들을 map<string, int>에 저장, 메뉴이름, 불린 횟수를 저장함
int의 최대값인 것의 string을 answer에 저장

-- 예외처리
1. 2 이상의 손님이 주문해야 함
    -> 불린 횟수의 최대값이 2보다 낮으면 pass
2. 메뉴의 순서가 정렬되어 있지 않은 경우
    -> 조합할 때, string을 정렬해서 삽입
*/