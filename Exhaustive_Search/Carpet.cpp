#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<vector<int>> yellow_vecs;
    for(int i = 1 ; i <= sqrt(yellow); i++)
        if(yellow % i == 0)
        {
            vector<int> temp;
            temp.push_back(yellow/i);
            temp.push_back(i);            
            yellow_vecs.push_back(temp);
        }
    
    for(vector<int> yellow_vec : yellow_vecs)
        if(yellow_vec[0] * 2 + yellow_vec[1] * 2 + 4 == brown)
        {
            for(int i : yellow_vec)
                answer.push_back(i + 2);
            break;
        }
    
    return answer;
}