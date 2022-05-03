#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compareID(string id, string ban)
{
    int id_length = id.length();
    int ban_length = ban.length();

    if(id_length != ban_length) return false;
    for(int i = 0 ; i < id_length ; i++)
    {
        if(ban[i] != '*' && id[i] != ban[i])
            return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    unordered_set<string> banned_list;

    sort(user_id.begin(), user_id.end());
    do
    {
        int i = 0;
        vector<string> temp;
        for( ; i < banned_id.size() ; i++)
        {
            if(compareID(user_id[i], banned_id[i]))
            {
                temp.push_back(user_id[i]);
                continue;
            }
            else break;
        }
        if(i == banned_id.size())
        {
            sort(temp.begin(), temp.end());
            string str = "";
            for(string s : temp)
                str += s;
            banned_list.insert(str);
        }
    } while (next_permutation(user_id.begin(), user_id.end()));
    
    return banned_list.size();
}

// https://programmers.co.kr/learn/courses/30/lessons/64064

/*
유저 id가 주어짐, 불량 id *가 포함된 아이디가 주어짐
1234, 5678, 1678 // *678
-> 불량 아이디는 5678 1678가 될 수 있음
-> 단, 불량 아이디에 한번 사용된 아이디는 다시 사용할 수 없음

1234, 5678, 1678 // *678, *678
-> 이 경우, 불량 아이디는 5678, 1678가 됨

banned_id의 선택에서는 순서가 중요하지 않기 때문에
banned_id가 될 수 있는 index를 선택, string을 만든 뒤, string을 정렬함
이후 string을 map에 넣음
이렇게 하면 map의 key값들은 banned_id가 될 수 있는 조합들이 나옴
즉, key의 갯수를 return하면 됨
*678 *678
1: 1234 5678 1678
2: 1234 1678 5678
3: 5678 1234 1678
4: 5678 1678 1234
5: 1678 1234 5678
6: 1678 5678 1234
->4, 6이 선택됨
id를 순열을 이용해 앞에서부터 banned_id와 매칭이 정확하게 일어나면 answer++
    단, 똑같은 id가 선택된 경우에는 answer++하지 않음
    -> id를 저장, 정렬해 string으로 변환하여 set에 insert하면 중복 id 선택은 제외됨


*/