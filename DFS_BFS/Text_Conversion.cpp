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
����
-�׷����� ����
    -�ѱ��� �����ΰ� Ȯ���ϴ� �Լ� �ʿ�
    -�ߺ��� ����� ���ΰ�? x �ߺ��� ����ϸ� �ּҰ��� ������ ���� ��
        -isVisited[] ����
    -�׷����� ������ �������� �� ���ΰ�? - begin �ܾ�� 1���� ���̳��� �ܾ��
    -�׷����� ������ ��, depth�� 0���� 1�� �����ϸ鼭 Ȯ���ؾ� ��
    -�׷����� �迭�� ����, pair<string, int>�� string���� word, int���� depth�� ����
-target�� �ش��ϴ� words�� �迭�� ������ ��, ã���Ͱ� ��������, depth�� answer�� ����
-�迭�� �� �����ߴµ� target�� ���� ���� ���ٸ� answer�� 0
*/
