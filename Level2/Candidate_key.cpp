#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<vector<string>> relations) {
    int answer = 0;
    int column = relations[0].size();
    int row = relations.size();
    vector<bool> isUsed(relations[0].size(), false);
    vector<string> combi_vec;
    
    //i는 false의 수, 선택하지 않는 attribute의 수
    for(int i = column - 1 ; i >= 0 ; i--)
    {
        vector<bool> combi(i, false);
        combi.insert(combi.end(), column - i, true);
        do
        {
            unordered_set<string> s;

            for(vector<string> relation : relations)
            {
                string str = "";
                for(int i = 0 ; i < column ; i++)
                {
                    if(combi[i]) str += relation[i];
                }
                s.insert(str);
            }
            if(s.size() == row)
            {
                string temp = "";
                for(int i = 0 ; i < column ; i++)
                {
                    if(combi[i])
                    {
                        isUsed[i] = true;
                        temp += to_string(i);
                    }
                }
                combi_vec.push_back(temp);
            }
        }while(next_permutation(combi.begin(), combi.end()));
    }
    
    isUsed.clear();
    isUsed.insert(isUsed.end(), combi_vec.size(), false);
    for(int i = 0 ; i < combi_vec.size() ; i++)
    {
        if(isUsed[i]) continue;
        isUsed[i] = true;
        answer++;

        string temp = combi_vec[i];
        cout << temp << "\n";
        for(int j = i+1 ; j < combi_vec.size() ; j++)
        {
            int k = 0;
            for( ; k < temp.length() ; k++)
            {
                if(combi_vec[j].find(temp[k]) == string::npos)
                {
                    break;
                }
            }
            if(k == temp.length())
            {
                isUsed[j] = true;
            }
        }
    }

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42890

/*
유일성 : 모든 튜플에 대해 유일하게 식별되어야 함, 즉 중복되는 값이 있으면 안됨
최소성 : 어느 하나의 속성이라도 제외하는 경우에도 유일성이 보장된다면 옳지 않음

유일성에 해당하기 위해 각 요소들을 set에 저장, set의 크기가 요소들의 갯수와 동일하면 유일함
    (set은 중복을 허용하지 않기 때문에 중복된 경우, 갯수가 동일하지 않게 됨)

최소성을 보장하기 위해 유일성 단계에서 추출한 조합을 사용해
작은 요소부터 사용, 이후 나오는 요소에 중복되어지는 요소가 있다면 제거
ex) 0, 01, 02, 12, 123
-> 0을 만나고 이후 01, 02, 12, 123이 있음
   01, 02에 0이 중복되어짐
   01, 02제거
-> 12를 만나고 이후 123이 있음
   123에는 12가 중복되어짐
   123제거
답 : 2개
*/
