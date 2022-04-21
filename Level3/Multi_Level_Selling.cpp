#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, int> money;
    unordered_map<string, int> index;

    for(int i = 0 ; i < enroll.size() ; i++)
    {
        money[enroll[i]] = 0;
        index[enroll[i]] = i;
    }

    for(int i = 0 ; i < seller.size() ; i++)
    {
        string sell = seller[i];
        int original = amount[i] * 100;
        int ten_percent = original / 10;
        int get_money = original - ten_percent;
        money[seller[i]] += get_money;

        while(ten_percent != 0)
        {
            sell = referral[index[sell]];
            if(sell == "-") break;
            int next_ten_percent = ten_percent / 10;
            get_money = ten_percent - next_ten_percent;
            money[sell] += get_money;

            ten_percent = next_ten_percent;
        }
    }

    for(string name : enroll)
        answer.push_back(money[name]);

    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/77486

/*
map에다가 판매원들에 대한 돈을 저장함

판매원이 돈을 벌 때 마다 10%를 때 추천인에게 전달해야함
*/