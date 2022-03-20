#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isClose(string a, string b)
{
    bool flag = false;
    for(int i = 0 ; i < a.length()  ; i++)
    {
        if(a[i] != b[i])
        {
            if(!flag)
                flag = true;
            else
                return false;
        }
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    //int answer = 0;
    int depth = 1;
    string first_word = "";

    queue<pair<string, int>> words_graph;
    bool *isVisited = new bool[words.size()]{false};

    for(int i = 0 ; i < words.size() ; i++)
    {
        if(words[i] == begin) isVisited[i] = true;
        if(isClose(begin, words[i]) && !isVisited[i])
        {
            if(words[i] == target) return 1;
            first_word = words[i];
            isVisited[i] = true;
            break;
        }
    }

    words_graph.push(make_pair(first_word, depth));
    while(!words_graph.empty())
    {
        pair<string, int> temp = words_graph.front();
        words_graph.pop();
        for(int i = 0 ; i < words.size() ; i++)
        {
            if(!isVisited[i] && isClose(temp.first, words[i]))
            {
                if(words[i] == target) return depth + 1;
                words_graph.push(make_pair(words[i], depth + 1));
                isVisited[i]  = true;
            }
        }
        depth = words_graph.front().second;
    }

    //return answer;
    return 0;
}

//https://programmers.co.kr/learn/courses/30/lessons/43163

/*
생각
-그래프를 제작
    -한글자 차이인가 확인하는 함수 필요
    -중복을 허용할 것인가? x 중복을 허용하면 최소값이 나오지 않을 듯
        -isVisited[] 제작
    -그래프의 시작을 무엇으로 할 것인가? - begin 단어랑 1글자 차이나는 단어로
    -그래프를 제작할 때, depth를 0부터 1씩 증가하면서 확인해야 함
    -그래프를 배열로 생성, pair<string, int>로 string에는 word, int에는 depth를 저장
-target에 해당하는 words를 배열에 저장할 때, 찾은것과 마찬가지, depth를 answer에 저장
-배열을 다 저장했는데 target과 같은 것이 없다면 answer은 0
*/
